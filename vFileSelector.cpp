#include "vFileSelector.h"
#include "ui_vFileSelector.h"

#include <QFileDialog>
#include <QStyle>

vFileSelector::vFileSelector(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::vFileSelector)
{
    ui->setupUi(this);
    setDialogCaption("Select a text file");
    setFilter("Text file (*.txt)");

}

vFileSelector::~vFileSelector()
{
    delete ui;
}

void vFileSelector::on_btnBrowse_clicked()
{
    auto filePath = QFileDialog::getOpenFileName(this, dialogCaption(),
                                                 "/home",
                                                 filter());
    if (filePath.length() > 0) {
        setPath(filePath);
    }
}

const QString &vFileSelector::dialogCaption() const
{
    return _dialogCaption;
}

void vFileSelector::setDialogCaption(const QString &newDialogCaption)
{
    if (_dialogCaption == newDialogCaption)
        return;
    _dialogCaption = newDialogCaption;
    emit dialogCaptionChanged();
}

const QString &vFileSelector::filter() const
{
    return _filter;
}

void vFileSelector::setFilter(const QString &newFilter)
{
    if (_filter == newFilter)
        return;
    _filter = newFilter;
    emit filterChanged();
}

const QString &vFileSelector::path() const
{
    return _path;
}

void vFileSelector::setPath(const QString &newPath)
{
    if (_path == newPath)
        return;
    _path = newPath;
    ui->lnFilePath->setText(newPath);
    emit fileSelected(newPath);
    QString isValid = "1";
    if (newPath.length() > 0) {
        QFileInfo info(newPath);
        if (!info.exists() || !info.isFile()) {
            isValid = "0";
        }
    }
    ui->lnFilePath->setProperty("isValid", isValid);
    style()->polish(ui->lnFilePath);

    emit pathChanged();
}

const QString vFileSelector::caption() const
{
    return ui->lblCaption->text();
}

void vFileSelector::setCaption(const QString &newCaption)
{
    ui->lblCaption->setText(newCaption);
    emit captionChanged();
}


void vFileSelector::on_lnFilePath_textChanged(const QString &arg1)
{
    setPath(arg1);
}

