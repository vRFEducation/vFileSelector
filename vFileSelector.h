#ifndef VFILESELECTOR_H
#define VFILESELECTOR_H

#include <QWidget>

namespace Ui {
    class vFileSelector;
}

class vFileSelector : public QWidget
{
    Q_OBJECT

public:
    vFileSelector(QWidget *parent = 0);
    ~vFileSelector();
    const QString caption() const;
    void setCaption(const QString &newCaption);

    const QString &path() const;
    void setPath(const QString &newPath);

    const QString &filter() const;
    void setFilter(const QString &newFilter);

    const QString &dialogCaption() const;
    void setDialogCaption(const QString &newDialogCaption);

private slots:
    void on_btnBrowse_clicked();

    void on_lnFilePath_textChanged(const QString &arg1);

signals:
    void fileSelected(QString);

    void captionChanged();

    void pathChanged();

    void filterChanged();

    void dialogCaptionChanged();

private:
    Ui::vFileSelector *ui;

    QString _path;
    QString _filter;
    QString _dialogCaption;
    Q_PROPERTY(QString caption READ caption WRITE setCaption NOTIFY captionChanged)
    Q_PROPERTY(QString path READ path WRITE setPath NOTIFY pathChanged)
    Q_PROPERTY(QString filter READ filter WRITE setFilter NOTIFY filterChanged)
    Q_PROPERTY(QString dialogCaption READ dialogCaption WRITE setDialogCaption NOTIFY dialogCaptionChanged)
};

#endif // VFILESELECTOR_H
