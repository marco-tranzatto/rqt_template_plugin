/*
 * TemplatePlugin.cpp
 *
 *  Created on: November 23, 2017
 *      Author: Marco Tranzatto (marco-tranzatto)
 */
#include "rqt_template_plugin/TemplatePlugin.hpp"

#include <pluginlib/class_list_macros.h>
#include <QGridLayout>
#include <QStringList>

#include <rqt_template_plugin/TemplateWidget.hpp>

//PLUGINLIB_EXPORT_CLASS(rqt_template_plugin::TemplatePlugin, rqt_gui_cpp::Plugin)
PLUGINLIB_DECLARE_CLASS(rqt_template_plugin, rqt_template_plugin::TemplatePlugin, rqt_template_plugin::TemplatePlugin, rqt_gui_cpp::Plugin)

namespace rqt_template_plugin {

TemplatePlugin::TemplatePlugin()
    : rqt_gui_cpp::Plugin(),
      widget_(0) {
  // Constructor is called first before initPlugin function, needless to say.

  // give QObjects reasonable names
  setObjectName("TemplatePlugin");
}

void TemplatePlugin::initPlugin(qt_gui_cpp::PluginContext &context) {
}

void TemplatePlugin::shutdownPlugin() {
}

void TemplatePlugin::saveSettings(qt_gui_cpp::Settings &plugin_settings,
                                  qt_gui_cpp::Settings &instance_settings) const {
}

void TemplatePlugin::restoreSettings(const qt_gui_cpp::Settings &plugin_settings,
                                     const qt_gui_cpp::Settings &instance_settings) {
}

} /* namespace */