#include "transferfunctioneditor.h"
#include "ui_transferfunctioneditor.h"

TransferFunctionEditor::TransferFunctionEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TransferFunctionEditor)
{
    ui->setupUi(this);
	ui->verticalLayout->addWidget(&widget);

	loadXML("../../transferfuncs/nucleon.tfi");
	widget.setTransferFunction(numIntensities, colors, intensities);
	widget.drawTransferFunction();
}

TransferFunctionEditor::~TransferFunctionEditor()
{
    delete ui;
}

void TransferFunctionEditor::on_action_Open_Transfer_Function_triggered()
{
	openTransferFunction();
}

void TransferFunctionEditor::on_action_Save_Transfer_Function_triggered()
{

}

void TransferFunctionEditor::on_makeRampButton_clicked()
{

}

void TransferFunctionEditor::on_makeLevelButton_clicked()
{

}
