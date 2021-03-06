#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "core/plugin_interfaces/IPlugin.h"
#include <QMainWindow>
#include <map>

namespace Ui {
class MainWindow;
}

namespace HighFlyers
{
class CoreController;

class MainWindow : public QMainWindow
{
	Q_OBJECT

private:
	Ui::MainWindow *ui;
	CoreController* controller;
	std::map<QString, QWidget*> plugin_widgets;

	void unload_plugin( QString plugin_name );

private Q_SLOTS:
	void load_plugin();
	void add_sample_dock(); //nowy slot bo cos smiesznego jest napisane pod load_plugins

public:
	explicit MainWindow( QWidget *parent = 0 );
	~MainWindow();

	void plugin_added( IPlugin* plugin );
	void plugin_removed( QString filename );

	void set_controller( CoreController* controller );
};

}
#endif // MAINWINDOW_H
