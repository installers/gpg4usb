/*
 *      settingsdialog.cpp
 *
 *      Copyright 2008 gpg4usb-team <gpg4usb@cpunk.de>
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */

#include <QWidget>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include <QLabel>
#include <QGridLayout>
#include <QGroupBox>
#include <QDialogButtonBox>
#include <QRadioButton>
#include <QButtonGroup>
#include <QSettings>
#include "settingsdialog.h"

SettingsDialog::SettingsDialog()
{
    setWindowTitle(tr("Settings"));
    resize(500, 200);
    setModal(true);

    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(applySettings()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    groupBox1 = new QGroupBox(tr("Options"));
    groupBox2 = new QGroupBox("Action");

	QRadioButton *iconTextButton = new QRadioButton(tr("just test"));
	QRadioButton *iconIconsButton =new QRadioButton(tr("just icons"));
	QRadioButton *iconAllButton = new QRadioButton(tr("text and icons"));
	
	QHBoxLayout *iconStyleBox = new QHBoxLayout();
	iconStyleBox->addWidget(iconTextButton);
	iconStyleBox->addWidget(iconIconsButton);
	iconStyleBox->addWidget(iconAllButton);
	group1 = new QButtonGroup();
	
	QRadioButton *iconSizeSmall = new QRadioButton(tr("small"));
	QRadioButton *iconSizeMedium =new QRadioButton(tr("medium"));
	QRadioButton *iconSizeLarge = new QRadioButton(tr("large"));
	group1->addButton(iconSizeSmall,1);
	group1->addButton(iconSizeMedium,2);
	group1->addButton(iconSizeLarge,3);


	QHBoxLayout *iconSizeBox = new QHBoxLayout();
	iconSizeBox->addWidget(iconSizeSmall);
	iconSizeBox->addWidget(iconSizeMedium);
	iconSizeBox->addWidget(iconSizeLarge);

	groupBox1->setLayout(iconStyleBox);
	groupBox2->setLayout(iconSizeBox);
	
	
    QVBoxLayout *vbox2 = new QVBoxLayout();
    vbox2->addWidget(groupBox1);
	vbox2->addWidget(groupBox2);
	vbox2->addWidget(buttonBox);
    setLayout(vbox2);
    exec();
}

void SettingsDialog::applySettings()
{
	     QSettings settings;
     //settings.setValue("geometry", saveGeometry());

	qDebug() << group1->checkedId();
	switch (group1->checkedId()){
	case 1: 
     settings.setValue("toolbar/iconsize", QSize(12, 12));
     break;
     
     case 2:settings.setValue("toolbar/iconsize", QSize(24, 24));
     break;
     case 3:settings.setValue("toolbar/iconsize", QSize(32, 32));
     break;
 }
}