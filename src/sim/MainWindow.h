#pragma once

#include <QKeyEvent>
#include <QLabel>
#include <QMainWindow>
#include <QTimer>

#include "Controller.h"
#include "Lens.h"
#include "Model.h"

namespace Ui {
class MainWindow;
}

namespace mms {

class MainWindow : public QMainWindow {

    Q_OBJECT

public:
    MainWindow(
        Model* model,
        Lens* lens,
        Controller* controller,
        QWidget *parent = 0);

    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent* event);

private:
    Model* m_model;
    Lens* m_lens;
    Ui::MainWindow *ui;

    // Header-related members
    // TODO: MACK - refactor this into its own class

    QMap<QString, QLabel*> m_runStats;
    QMap<QString, QLabel*> m_algoOptions;
    QMap<QString, QLabel*> m_mazeInfo;
    QMap<QString, QLabel*> m_options;

    QVector<QPair<QString, QVariant>> getRunStats() const;
    QVector<QPair<QString, QVariant>> getAlgoOptions() const;
    QVector<QPair<QString, QVariant>> getMazeInfo() const;
    QVector<QPair<QString, QVariant>> getOptions() const;

    QTimer m_headerRefreshTimer;

};

} // namespace mms