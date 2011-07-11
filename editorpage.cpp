/*
 *      textpage.cpp
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

#include <QtGui>

#include "editorpage.h"


EditorPage::EditorPage(const QString &filePath, QWidget *parent) : QWidget(parent),
                                                       fullFilePath(filePath)
{
    textPage   = new QPlainTextEdit();
    verifyLabel = new QLabel("Verified");
    verifyLabel->setAutoFillBackground(1);
    QPalette verifyPalette = verifyLabel->palette();
    verifyPalette.setColor(QPalette::Background, "#CBFDCB");
    verifyLabel->setPalette(verifyPalette);
    this->showVerifyLabel(false);
    mainLayout = new QVBoxLayout();
    mainLayout->setSpacing(0);
    mainLayout->addWidget(textPage);
    mainLayout->addWidget(verifyLabel);
    mainLayout->setContentsMargins(0,0,0,0);
    setLayout(mainLayout);
    setAttribute(Qt::WA_DeleteOnClose);
    textPage->setFocus();
}


const QString& EditorPage::getFilePath() const
{
    return fullFilePath;
}


QPlainTextEdit* EditorPage::getTextPage()
{
    return textPage;
}


void EditorPage::setFilePath(const QString &filePath)
{
    fullFilePath = filePath;
}

void EditorPage::showVerifyLabel(bool showLabel)
{
    if (showLabel == true) {
        verifyLabel->show();
    } else {
        verifyLabel->hide();
    }
}

void setSaveState()
{
   // curPage()->setFilePath("");
}
