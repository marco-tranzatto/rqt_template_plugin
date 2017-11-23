/*
 * TemplateWidget.hpp
 *
 *  Created on: November 23, 2017
 *      Author: Marco Tranzatto (marco-tranzatto)
 */

#ifndef RQT_TEMPLATE_PLUGIN_TEMPLATEWIDGET_HPP
#define RQT_TEMPLATE_PLUGIN_TEMPLATEWIDGET_HPP

#include <QDockWidget>
#include <QStringList>
#include <QWidget>

namespace Ui {
class TemplateWidget;
};

namespace rqt_template_plugin {

class TemplateWidget :
    public QWidget {
 Q_OBJECT
 public:
  TemplateWidget(QWidget *parent = 0);
  virtual ~TemplateWidget();

 private:
  Ui::TemplateWidget *ui_;
};

} /* namespace */
#endif //RQT_TEMPLATE_PLUGIN_TEMPLATEWIDGET_HPP
