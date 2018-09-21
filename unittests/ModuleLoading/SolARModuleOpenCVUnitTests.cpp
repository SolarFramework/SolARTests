#define BOOST_TEST_MODULE SolARModuleOpenCVUnitTests


#include <boost/log/core.hpp>
#include "xpcf/xpcf.h"
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

       // org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");

          org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");
//D:\DEV\SolAR\sources\Modules\SolARModuleOpenCV\

        BOOST_TEST(retCode==org::bcom::xpcf::_SUCCESS,"SOLAR ERROR: xpcfComponentManager could not be opened");
    }

    /* this test uses an XML file that does not exist*/
    /* this test should fail*/
    BOOST_AUTO_TEST_CASE(TestLoadNotExistingModule)
    {

    #if NDEBUG
        boost::log::core::get()->set_logging_enabled(false);
    #endif

        // load library
        SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

        org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/none.xml");


        BOOST_TEST(retCode==org::bcom::xpcf::_FAIL,"SOLAR ERROR: xpcfComponentManager should return _ERROR_MODULE_UNKNOWN but returns " << retCode );

    }

    /* this test uses an XML file of module description with a XML syntax error*/
    /* this test should fail*/
    BOOST_AUTO_TEST_CASE(TestLoadXMLSyntaxError)
    {

    #if NDEBUG
        boost::log::core::get()->set_logging_enabled(false);
    #endif

        // load library
        SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

       org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("xpcf_SolARModuleOpenCVSyntaxError_registry.xml");

        BOOST_TEST(retCode==org::bcom::xpcf::_FAIL,"SOLAR ERROR: xpcfComponentManager should return _ERROR_MODULE_UNKNOWN but returns " << retCode );

    }

    /* this test uses an XML file of module description indicating a dll that does not exist*/
    /* this test should fail*/
    BOOST_AUTO_TEST_CASE(TestLoadXMLwithDLLmissing)
    {

    #if NDEBUG
        boost::log::core::get()->set_logging_enabled(false);
    #endif

        // load library
        SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

       org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("xpcf_SolARModuleOpenCVNonExistingDLL_registry.xml");

        BOOST_TEST(retCode==org::bcom::xpcf::_FAIL,"SOLAR ERROR: xpcfComponentManager should return _ERROR_MODULE_UNKNOWN but returns " << retCode );

    }

}

