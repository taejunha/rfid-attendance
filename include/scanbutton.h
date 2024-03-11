#ifndef SCAN_BUTTON_H
#define SCAN_BUTTON_H
#include <QPushButton>
#include <QMouseEvent>
#include "adminwindow.h"
#include "userwindow.h"

enum Status {
    checked_out = 0,
    checked_in = 1
};

class ScanButton : public QPushButton {
    Q_OBJECT

    public:
        ScanButton(const QString &text, QWidget *parent = nullptr);
        ~ScanButton();
    public slots:
        virtual void handleLeftClick();
        virtual void handleRightClick();
    protected: 
        Status account_status;
        AdminWindow *admin_window;
        UserWindow *user_window;
    protected slots:
        void mousePressEvent(QMouseEvent *event);
    signals:
        void rightClicked();
    private:
        void openAccountWindow(UserWindow *account_window);
        void openAccountWindow(AdminWindow *account_window);
};

#endif
