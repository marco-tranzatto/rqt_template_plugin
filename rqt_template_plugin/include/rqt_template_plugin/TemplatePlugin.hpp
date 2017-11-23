/*
 * TemplatePlugin.hpp
 *
 *  Created on: November 23, 2017
 *      Author: Marco Tranzatto (marco-tranzatto)
 */

#ifndef RQT_TEMPLATE_PLUGIN_TEMPLATEPLUGIN_HPP
#define RQT_TEMPLATE_PLUGIN_TEMPLATEPLUGIN_HPP

#include <QStringList>
#include <rqt_gui_cpp/plugin.h>
#include <QWidget>
#include <unistd.h>

namespace rqt_template_plugin {

class TemplateWidget;

class TemplatePlugin : public rqt_gui_cpp::Plugin {
 Q_OBJECT
 public:
  TemplatePlugin();
  virtual ~TemplatePlugin();

  virtual void initPlugin(qt_gui_cpp::PluginContext &context);
  virtual void shutdownPlugin();
  virtual void saveSettings(qt_gui_cpp::Settings &plugin_settings, qt_gui_cpp::Settings &instance_settings) const;
  virtual void restoreSettings(const qt_gui_cpp::Settings &plugin_settings,
                               const qt_gui_cpp::Settings &instance_settings);

  // Comment in to signal that the plugin has a way to configure it
  //bool hasConfiguration() ch ficonst;
  //void triggerConfiguration();

 private:
  TemplateWidget* widget_;
};

} /* namespace */

#endif /* RQT_TEMPLATE_PLUGIN_TEMPLATEPLUGIN_HPP */
