#ifndef FIELDSVIEW_H
#define FIELDSVIEW_H

#include <QDialog>

#include "Class.h"

namespace Ui {
class FieldsView;
}

class FieldsView : public QDialog
{
    Q_OBJECT
    
public:
    explicit FieldsView(Class classData, QWidget *parent = 0);
    ~FieldsView();
    
private:
    Ui::FieldsView *ui;
    Class classData;
};

#endif // FIELDSVIEW_H
