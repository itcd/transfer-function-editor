#ifndef TRANSFERFUNCTIONEDITOR_H
#define TRANSFERFUNCTIONEDITOR_H

#include <QMainWindow>
#include <iostream>
#include <QFileDialog>
#include "glm/glm.hpp"
#include "tinyxml2.h"
#include "graphwidget.h"
#include "TransferFunctionView.h"

namespace Ui {
class TransferFunctionEditor;
}

class TransferFunctionEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit TransferFunctionEditor(QWidget *parent = 0);
    ~TransferFunctionEditor();

    void loadXML(const char *filename)
    {
        tinyxml2::XMLDocument doc;
        //auto r = doc.LoadFile("../../Samples/CTknee/transfer_function/CT-Knee_spectrum_16_balance.tfi");
        auto r = doc.LoadFile(filename);

        if (r != tinyxml2::XML_NO_ERROR)
            std::cout << "failed to open file" << std::endl;

        auto transFuncIntensity = doc.FirstChildElement("VoreenData")->FirstChildElement("TransFuncIntensity");

        auto key = doc.FirstChildElement("VoreenData")->FirstChildElement("TransFuncIntensity")->FirstChildElement("Keys")->FirstChildElement("key");

        while (key)
        {
            float intensity = atof(key->FirstChildElement("intensity")->Attribute("value"));
            intensities.push_back(intensity);

            int r = atoi(key->FirstChildElement("colorL")->Attribute("r"));
            int g = atoi(key->FirstChildElement("colorL")->Attribute("g"));
            int b = atoi(key->FirstChildElement("colorL")->Attribute("b"));
            int a = atoi(key->FirstChildElement("colorL")->Attribute("a"));

            colors.push_back(glm::vec4(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f));

            std::cout << "intensity=" << intensity;
            std::cout << "\tcolorL r=" << r << " g=" << g << " b=" << b << " a=" << a;
            std::cout << std::endl;

            key = key->NextSiblingElement();
        }

        numIntensities = intensities.size();
    }

	void openTransferFunction()
	{
		QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
			"../../transferfuncs/nucleon.tfi",
			tr("Voreen Transfer Function (*.tfi) ;; All (*.*)"));
		std::cout << "size" << fileName.size() << std::endl;
		if (fileName.size() > 0)
		{
			QByteArray array = fileName.toLocal8Bit();
			char* buffer = array.data();

			std::cout << buffer << " loaded" << std::endl;
			intensities.clear();
			colors.clear();
			loadXML(buffer);
			std::cout << numIntensities << " " << intensities.size() << " " << colors.size() << std::endl;
			widget.setTransferFunction(numIntensities, colors, intensities);
			widget.drawTransferFunction();
		}
	}

private slots:
    void on_action_Open_Transfer_Function_triggered();

    void on_action_Save_Transfer_Function_triggered();

    void on_makeRampButton_clicked();

    void on_makeLevelButton_clicked();

private:
    Ui::TransferFunctionEditor *ui;

    TransferFunctionView widget;
    int numIntensities;
    std::vector<glm::vec4> colors;
    std::vector<float> intensities;
};

#endif // TRANSFERFUNCTIONEDITOR_H
