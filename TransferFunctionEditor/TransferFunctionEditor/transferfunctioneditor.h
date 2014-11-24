#ifndef TRANSFERFUNCTIONEDITOR_H
#define TRANSFERFUNCTIONEDITOR_H

#include <QMainWindow>
#include <iostream>
#include <QFileDialog>

#include "for_volume_renderer.h"

#include "glm/glm.hpp"
#include "tinyxml2.h"
#include "graphwidget.h"
#include "ControlEdge.h"
#include "ControlPoint.h"
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

	/// open transfer function from Voreen XML
    void openTransferFunctionFromVoreenXML(const char *filename)
    {
		tinyxml2::XMLDocument doc;
		auto r = doc.LoadFile(filename);

		if (r != tinyxml2::XML_NO_ERROR)
		{
			std::cout << "failed to open file " << filename << std::endl;
			return;
		}

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

	/// save transfer function as Voreen XML
	void saveTransferFunctionToVoreenXML(const char *filename)
	{
		tinyxml2::XMLDocument doc;

		auto declaration = doc.NewDeclaration();
		doc.InsertEndChild(declaration);
		auto voreenData = doc.NewElement("VoreenData");
		voreenData->SetAttribute("version", 1);
		auto transFuncIntensity = doc.NewElement("TransFuncIntensity");
		transFuncIntensity->SetAttribute("type", "TransFuncIntensity");

		// add domain
		auto domain = doc.NewElement("domain");
		domain->SetAttribute("x", 0);
		domain->SetAttribute("y", 1);
		transFuncIntensity->InsertEndChild(domain);

		// add threshold
		auto threshold = doc.NewElement("threshold");
		threshold->SetAttribute("x", 0);
		threshold->SetAttribute("y", 1);
		transFuncIntensity->InsertEndChild(threshold);

		// add Keys
		auto size = intensities.size();
		auto keys = doc.NewElement("Keys");
		for (int i = 0; i < size; i++)
		{
			auto key = doc.NewElement("key");
			key->SetAttribute("type", "TransFuncMappingKey");
			auto intensity = doc.NewElement("intensity");
			intensity->SetAttribute("value", intensities[i]);
			auto split = doc.NewElement("split");
			split->SetAttribute("value", "false");
			auto colorL = doc.NewElement("colorL");
			auto c = colors[i];
			colorL->SetAttribute("r", static_cast<int>(c.r * 255));
			colorL->SetAttribute("g", static_cast<int>(c.g * 255));
			colorL->SetAttribute("b", static_cast<int>(c.b * 255));
			colorL->SetAttribute("a", static_cast<int>(c.a * 255));
			key->InsertEndChild(intensity);
			key->InsertEndChild(split);
			key->InsertEndChild(colorL);
			keys->InsertEndChild(key);
		}
		transFuncIntensity->InsertEndChild(keys);

		voreenData->InsertEndChild(transFuncIntensity);
		doc.InsertEndChild(voreenData);

		auto r = doc.SaveFile(filename);
		if (r != tinyxml2::XML_NO_ERROR)
		{
			std::cout << "failed to save file " << filename << std::endl;
		}
	}

#ifdef USED_BY_VOLUME_RENDERER
	void init(VolumeRenderer volumeRenderer)
	{
		std::cout << "TransferFunctionEditor::Init" << std::endl;
		tf.transfer_function = &(volumeRenderer.renderer->transferFunction);
	}
#endif // USED_BY_VOLUME_RENDERER

private slots:
    void on_action_Open_Transfer_Function_triggered();

    void on_action_Save_Transfer_Function_triggered();

    void on_distributeHorizontallyButton_clicked();

    void on_distributeVerticallyButton_clicked();

    void on_levelButton_clicked();

    void on_diagonalButton_clicked();
private:
    Ui::TransferFunctionEditor *ui;

    TransferFunctionView tf;
    int numIntensities;
    std::vector<glm::vec4> colors;
    std::vector<float> intensities;
	QString filename;
};

#endif // TRANSFERFUNCTIONEDITOR_H
