/** @file GEMReadoutWebApplication.h */

#ifndef GEM_READOUT_GEMREADOUTWEBAPPLICATION_H
#define GEM_READOUT_GEMREADOUTWEBAPPLICATION_H

#include "gem/base/GEMWebApplication.h"

namespace gem {
  namespace readout {

    class GEMReadoutApplication;

    class GEMReadoutWebApplication : public gem::base::GEMWebApplication
      {
        //friend class GEMReadoutMonitor;
        friend class GEMReadoutApplication;

      public:
        GEMReadoutWebApplication(GEMReadoutApplication *readoutApp);

        virtual ~GEMReadoutWebApplication();

      protected:

        virtual void webDefault(  xgi::Input *in, xgi::Output *out );

        virtual void monitorPage(xgi::Input *in, xgi::Output *out);

        virtual void expertPage(xgi::Input *in, xgi::Output *out);

        virtual void applicationPage(xgi::Input *in, xgi::Output *out);

        virtual void jsonUpdate(xgi::Input *in, xgi::Output *out);

      private:
        //GEMReadoutWebApplication(GEMReadoutWebApplication const&);
      };
  }  // namespace gem::readout
}  // namespace gem

#endif  // GEM_READOUT_GEMREADOUTWEBAPPLICATION_H
