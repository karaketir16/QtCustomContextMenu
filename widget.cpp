#include "widget.h"
#include "ui_widget.h"
#include <QMenu>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableWidget, &QTableWidget::customContextMenuRequested, this, &Widget::fonk);
    QStringList headers;
    headers.append("sütun1");
    headers.append("sütun2");
    ui->tableWidget->setColumnCount(headers.length());
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->setRowCount(5);
    for(int i =0; i < 5; i++)
    {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem("Test"));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem("Test"));
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::fonk(const QPoint &pos)
{
    QMenu menu;
    QAction *act1 = menu.addAction("seçim1");
    QAction *act2 = menu.addAction("seçim2");
    QAction *res = menu.exec(ui->tableWidget->viewport()->mapToGlobal(pos));
}
