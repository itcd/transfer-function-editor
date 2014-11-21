#include "transferfunctioneditor.h"
#include "ui_transferfunctioneditor.h"

TransferFunctionEditor::TransferFunctionEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TransferFunctionEditor)
{
    ui->setupUi(this);
    ui->horizontalLayout->addWidget(&widget);

	LoadXML("../../transferfuncs/nucleon.tfi");
	widget.setTransferFunction(numIntensities, colors, intensities);
	widget.drawTransferFunction();
}

TransferFunctionEditor::~TransferFunctionEditor()
{
    delete ui;
}

void TransferFunctionEditor::on_action_Load_Transfer_Function_triggered()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
		"../../transferfuncs/nucleon.tfi",
		tr("Voreen Transfer Function (*.tfi) ;; All (*.*)"));
	std::cout<<"size"<<fileName.size()<<std::endl;
	if (fileName.size() > 0)
	{
		QByteArray array = fileName.toLocal8Bit();
		char* buffer = array.data();
		
		std::cout<<buffer<<" loaded"<<std::endl;
		intensities.clear();
		colors.clear();
		LoadXML(buffer);
		std::cout<<numIntensities<<" "<<intensities.size()<<" "<<colors.size()<<std::endl;
		widget.setTransferFunction(numIntensities, colors, intensities);
		widget.drawTransferFunction();
	}
}
