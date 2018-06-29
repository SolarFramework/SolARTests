#define BOOST_TEST_MODULE SolARModuleOpenCVUnitTests


#include <boost/log/core.hpp>
#include "IComponentManager.h"
#include <boost/test/unit_test.hpp>

namespace xpcf  = org::bcom::xpcf;

namespace SolAR {

    BOOST_AUTO_TEST_CASE(TestLoadModule)
    {

    #if NDEBUG
        boost::log::core::get()->set_logging_enabled(false);
    #endif

        // load library
        SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

        org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");


        BOOST_TEST(retCode==org::bcom::xpcf::_SUCCESS,"SOLAR ERROR: xpcfComponentManager could not be opened");

    }

    BOOST_AUTO_TEST_CASE(TestLoadNotExistingModule)
    {

    #if NDEBUG
        boost::log::core::get()->set_logging_enabled(false);
    #endif

        // load library
        SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

        org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/none.xml");


        BOOST_TEST(retCode==org::bcom::xpcf::_ERROR_MODULE_UNKNOWN,"SOLAR ERROR: xpcfComponentManager should return _ERROR_MODULE_UNKNOWN but returns " << retCode );

    }

}

