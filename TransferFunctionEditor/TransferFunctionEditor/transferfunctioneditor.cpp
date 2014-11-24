#include "transferfunctioneditor.h"
#include "ui_transferfunctioneditor.h"

TransferFunctionEditor::TransferFunctionEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TransferFunctionEditor)
{
    ui->setupUi(this);

	// add transfer function widget
	ui->verticalLayout->addWidget(&tf);

	// load default transfer function
	filename = "../../transferfuncs/nucleon.tfi";
	QByteArray array = filename.toLocal8Bit();
	char* buffer = array.data();
	openTransferFunctionFromVoreenXML(buffer);
	tf.setTransferFunction(numIntensities, colors, intensities);
	tf.drawTransferFunction();
}

TransferFunctionEditor::~TransferFunctionEditor()
{
    delete ui;
}

void TransferFunctionEditor::on_action_Open_Transfer_Function_triggered()
{
	QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), "../../transferfuncs/nucleon.tfi", tr("Voreen Transfer Function (*.tfi) ;; All (*.*)"));
	std::cout << "size" << filename.size() << std::endl;
	if (filename.size() > 0)
	{
		QByteArray array = filename.toLocal8Bit();
		char* buffer = array.data();
		std::cout << "Open transfer function from " << buffer << std::endl;
		intensities.clear();
		colors.clear();
		openTransferFunctionFromVoreenXML(buffer);
		//std::cout << numIntensities << " " << intensities.size() << " " << colors.size() << std::endl;
		tf.setTransferFunction(numIntensities, colors, intensities);
		tf.drawTransferFunction();
	}
}

void TransferFunctionEditor::on_action_Save_Transfer_Function_triggered()
{
	tf.getTransferFunction(numIntensities, colors, intensities);
	QString filename = QFileDialog::getSaveFileName(this, tr("Save File"), "../../transferfuncs/save_as.tfi", tr("Voreen Transfer Function (*.tfi) ;; All (*.*)"));
	std::cout << "size" << filename.size() << std::endl;
	if (filename.size() > 0)
	{
		QByteArray array = filename.toLocal8Bit();
		char* buffer = array.data();
		std::cout << "Save transfer function to " << buffer << std::endl;
		saveTransferFunctionToVoreenXML(buffer);
	}
}

void TransferFunctionEditor::on_makeRampButton_clicked()
{
	tf.makeRamp();
}

void TransferFunctionEditor::on_makeLevelButton_clicked()
{
	tf.makeLevel();
}

void TransferFunctionEditor::on_distributeHorizontallyButton_clicked()
{
	tf.distrubuteHorizontally();
}

void TransferFunctionEditor::on_distributeVerticallyButton_clicked()
{
	tf.distributeVertically();
}
