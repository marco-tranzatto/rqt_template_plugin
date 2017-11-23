/*
 * TemplateWidget.cpp
 *
 *  Created on: November 23, 2017
 *      Author: Marco Tranzatto (marco-tranzatto)
 */

#include "rqt_template_plugin/TemplateWidget.hpp"

#include "ui_template_widget.h"

namespace rqt_template_plugin {

/*****************************************************************************/
/* Constructors and Destructor                                               */
/*****************************************************************************/

TemplateWidget::TemplateWidget(QWidget *parent) :
    QWidget(parent),
    ui_(new Ui::TemplateWidget()) {
  ui_->setupUi(this);
}

TemplateWidget::~TemplateWidget() {
  //confirmClose();

  delete ui_;
}

} /* namespace */