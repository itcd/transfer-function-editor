#include "transferfunctioneditor.h"
#include "ui_transferfunctioneditor.h"

TransferFunctionEditor::TransferFunctionEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TransferFunctionEditor)
{
    ui->setupUi(this);
	ui->verticalLayout->addWidget(&tf);

	loadXML("../../transferfuncs/nucleon.tfi");
	tf.setTransferFunction(numIntensities, colors, intensities);
	tf.drawTransferFunction();
}

TransferFunctionEditor::~TransferFunctionEditor()
{
    delete ui;
}

void TransferFunctionEditor::on_action_Open_Transfer_Function_triggered()
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
		tf.setTransferFunction(numIntensities, colors, intensities);
		tf.drawTransferFunction();
	}
}

void TransferFunctionEditor::on_action_Save_Transfer_Function_triggered()
{
	tf.getTransferFunction(numIntensities, colors, intensities);
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
