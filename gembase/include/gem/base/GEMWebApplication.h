/** @file GEMWebApplication.h */

#ifndef GEM_BASE_GEMWEBAPPLICATION_H
#define GEM_BASE_GEMWEBAPPLICATION_H

#include <string>

#include "cgicc/HTMLClasses.h"

#include "xdaq/WebApplication.h"
#include "xgi/framework/Method.h"
#include "xgi/framework/UIManager.h"

#include "gem/utils/GEMLogging.h"

namespace xgi {
  class Input;
  class Output;
}

namespace cgicc {
  BOOLEAN_ELEMENT(section, "section");
}

namespace gem {
  namespace base {

    class GEMFSM;
    class GEMMonitor;
    class GEMApplication;
    class GEMFSMApplication;

    class GEMWebApplication
    {
      friend class GEMFSM;
      friend class GEMMonitor;
      friend class GEMApplication;
      friend class GEMFSMApplication;

    public:
      GEMWebApplication(GEMApplication* gemApp);

      GEMWebApplication(GEMFSMApplication* gemFSMApp);

      ~GEMWebApplication();

      static std::string jsonEscape(std::string const& orig);
      static std::string htmlEscape(std::string const& orig);

    protected:
      // maybe only have the control panel built in the base class?
      // perhaps can extend it in derived classes
      virtual void controlPanel(xgi::Input* in, xgi::Output* out);

      virtual void monitorPage(xgi::Input* in, xgi::Output* out);

      virtual void expertPage(xgi::Input* in, xgi::Output* out);

      virtual void applicationPage(xgi::Input* in, xgi::Output* out)=0;

      virtual void jsonStateUpdate(xgi::Input* in, xgi::Output* out);

      virtual void jsonUpdate(xgi::Input* in, xgi::Output* out);

      virtual void webRedirect(xgi::Input* in, xgi::Output* out);

      virtual void webDefault(xgi::Input* in, xgi::Output* out);

      void webFooterGEM(xgi::Input* in, xgi::Output* out);
      // fsm specific functions, only called when the constructing app is derived from a
      // GEMFSMApplication
      void webInitialize(xgi::Input* in, xgi::Output* out);
      void webEnable(xgi::Input* in, xgi::Output* out);
      void webConfigure(xgi::Input* in, xgi::Output* out);
      void webStart(xgi::Input* in, xgi::Output* out);
      void webPause(xgi::Input* in, xgi::Output* out);
      void webResume(xgi::Input* in, xgi::Output* out);
      void webStop(xgi::Input* in, xgi::Output* out);
      void webHalt(xgi::Input* in, xgi::Output* out);
      void webReset(xgi::Input* in, xgi::Output* out);

      log4cplus::Logger m_gemLogger;

      GEMMonitor*        p_gemMonitor;
      GEMFSMApplication* p_gemFSMApp;
      GEMApplication*    p_gemApp;
      // xdaq::Application* p_gemApp;

      bool b_is_working, b_is_initialized, b_is_configured, b_is_running, b_is_paused;

    private:
      GEMWebApplication(GEMWebApplication const&);
      void buildCfgWebpage();
    };
  }  // namespace gem::base
}  // namespace gem

#endif  // GEM_BASE_GEMWEBAPPLICATION_H
