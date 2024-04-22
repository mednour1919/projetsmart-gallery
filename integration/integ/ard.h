#ifndef ARD_H
#define ARD_H

#include <QDialog>

namespace Ui {
class ard;
}

class ard : public QDialog
{
    Q_OBJECT

public:
    explicit ard(QWidget *parent = nullptr);
    ~ard();

private:
    Ui::ard *ui;
};

#endif // ARD_H
