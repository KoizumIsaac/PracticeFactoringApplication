#ifndef FACTORINGMODEL_H
#define FACTORINGMODEL_H

#include <QObject>

class FactoringModel : public QObject
{
    Q_OBJECT

public:
    explicit FactoringModel(QObject *parent = nullptr);

signals:
};

#endif // FACTORINGMODEL_H
