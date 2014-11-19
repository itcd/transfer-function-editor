#ifndef TRANSFERFUNCTIONEDITOR_H
#define TRANSFERFUNCTIONEDITOR_H

#include <iostream>
#include <QtWidgets/QMainWindow>
#include "ui_transferfunctioneditor.h"
#include "glm/glm.hpp"
#include "tinyxml2.h"

class TransferFunctionEditor : public QMainWindow
{
	Q_OBJECT

public:
	TransferFunctionEditor(QWidget *parent = 0);
	~TransferFunctionEditor();

	void LoadXML(const char *filename)
	{
		tinyxml2::XMLDocument doc;
		//	auto r = doc.LoadFile("nucleon.tfi");
		auto r = doc.LoadFile("../../Samples/CTknee/transfer_function/CT-Knee_spectrum_16_balance.tfi");
		//	auto r = doc.LoadFile("../../Samples/downsampled vortex/90.tfi");

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

private:
	Ui::TransferFunctionEditorClass ui;

	int numIntensities;
	std::vector<glm::vec4> colors;
	std::vector<float> intensities;
};

#endif // TRANSFERFUNCTIONEDITOR_H
