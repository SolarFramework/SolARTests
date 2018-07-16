#define BOOST_TEST_MODULE SolARModuleOpenCVUnitTests


#include <boost/log/core.hpp>
#include "xpcf/xpcf.h"
#include <boost/test/unit_test.hpp>

#include "SolARModuleOpencv_traits.h"
#include "api/input/devices/ICamera.h"
#include "api/display/IImageViewer.h"
#include "api/input/files/IMarker2DNaturalImage.h"
#include "api/features/IKeypointDetector.h"
#include "api/features/IDescriptorMatcher.h"
#include "api/features/IDescriptorsExtractor.h"
#include "api/features/IMatchesFilter.h"
#include "api/features/IMatchesFilter.h"
#include "api/solver/pose/I2DTransformFinder.h"
#include "api/solver/pose/IHomographyValidation.h"
#include "api/features/IKeypointsReIndexer.h"
#include "api/solver/pose/I3DTransformFinder.h"
#include "api/display/I2DOverlay.h"
#include "api/display/ISideBySideOverlay.h"
#include "api/display/I3DOverlay.h"
#include "api/geom/IImage2WorldMapper.h"
#include "api/geom/I2DTransform.h"
#include "api/features/IContoursExtractor.h"
#include "api/features/IContoursFilter.h"
#include "api/features/IDescriptorsExtractorSBPattern.h"
#include "api/solver/pose/I2Dto3DTransformDecomposer.h"
#include "api/image/IImageConvertor.h"
#include "api/image/IImageFilter.h"
#include "api/image/IImageLoader.h"
#include "api/input/files/IMarker2DSquaredBinary.h"
#include "api/image/IPerspectiveController.h"
#include "api/solver/map/ITriangulator.h"
#include "api/input/devices/ICameraCalibration.h"


namespace xpcf  = org::bcom::xpcf;

using namespace SolAR;
using namespace SolAR::api;
using namespace SolAR::MODULES::OPENCV;

//dynamic part

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



BOOST_AUTO_TEST_CASE(TestLoad2DOverlayDynamic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif

    // load library
    SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

    org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");


    BOOST_TEST(retCode==org::bcom::xpcf::_SUCCESS,"SOLAR ERROR: xpcfComponentManager could not be opened");


    auto component = xpcfComponentManager->create<SolAR2DOverlayOpencv>()->bindTo<api::display::I2DOverlay>();

    BOOST_TEST(component,"SOLAR ERROR: 2DOverlay component could not be created in dynamic mode");

}

BOOST_AUTO_TEST_CASE(TestLoad3DOverlayDynamic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


        // load library
    SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

    org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");


    BOOST_TEST(retCode==org::bcom::xpcf::_SUCCESS,"SOLAR ERROR: xpcfComponentManager could not be opened");


    auto component = xpcfComponentManager->create<SolAR3DOverlayOpencv>()->bindTo<api::display::I3DOverlay>();

    BOOST_TEST(component,"SOLAR ERROR: 3DOverlay component could not be created in dynamic mode");

}

BOOST_AUTO_TEST_CASE(TestLoadCameraCalibrationDynamic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


        // load library
    SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

    org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");


    BOOST_TEST(retCode==org::bcom::xpcf::_SUCCESS,"SOLAR ERROR: xpcfComponentManager could not be opened");


    auto component = xpcfComponentManager->create<SolARCameraCalibrationOpencv>()->bindTo<api::input::devices::ICameraCalibration>();

    BOOST_TEST(component,"SOLAR ERROR: Camera Calibration component could not be created in dynamic mode");

}

BOOST_AUTO_TEST_CASE(TestLoadCameraDynamic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


        // load library
    SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

    org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");


    BOOST_TEST(retCode==org::bcom::xpcf::_SUCCESS,"SOLAR ERROR: xpcfComponentManager could not be opened");


    auto component = xpcfComponentManager->create<SolARCameraOpencv>()->bindTo<input::devices::ICamera>();

    BOOST_TEST(component,"SOLAR ERROR: Camera component could not be created in dynamic mode");

}

BOOST_AUTO_TEST_CASE(TestLoadContoursExtractorDynamic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


        // load library
    SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

    org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");


    BOOST_TEST(retCode==org::bcom::xpcf::_SUCCESS,"SOLAR ERROR: xpcfComponentManager could not be opened");


    auto component = xpcfComponentManager->create<SolARContoursExtractorOpencv>()->bindTo<api::features::IContoursExtractor>();

    BOOST_TEST(component,"SOLAR ERROR: Contours Extractor component could not be created in dynamic mode");

}

BOOST_AUTO_TEST_CASE(TestContoursFilterDynamic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


        // load library
    SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

    org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");


    BOOST_TEST(retCode==org::bcom::xpcf::_SUCCESS,"SOLAR ERROR: xpcfComponentManager could not be opened");


    auto component = xpcfComponentManager->create<SolARContoursFilterBinaryMarkerOpencv>()->bindTo<api::features::IContoursFilter>();

    BOOST_TEST(component,"SOLAR ERROR: Contours Filter component could not be created in dynamic mode");

}

BOOST_AUTO_TEST_CASE(TestLoadDescriptorMatcherHammingBruteForceOpencvDynamic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


        // load library
    SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

    org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");


    BOOST_TEST(retCode==org::bcom::xpcf::_SUCCESS,"SOLAR ERROR: xpcfComponentManager could not be opened");


    auto component = xpcfComponentManager->create<SolARDescriptorMatcherHammingBruteForceOpencv>()->bindTo<api::features::IDescriptorMatcher>();

    BOOST_TEST(component,"SOLAR ERROR: Descriptor Matcher Hamming Brute Force Opencv component could not be created in dynamic mode");

}


BOOST_AUTO_TEST_CASE(TestLoadDescriptorMatcherKNNOpencvDynamic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif

        // load library
    SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

    org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");


    BOOST_TEST(retCode==org::bcom::xpcf::_SUCCESS,"SOLAR ERROR: xpcfComponentManager could not be opened");


    auto component = xpcfComponentManager->create<SolARDescriptorMatcherKNNOpencv>()->bindTo<api::features::IDescriptorMatcher>();

    BOOST_TEST(component,"SOLAR ERROR: Descriptor Matcher KNN Opencv component could not be created in dynamic mode");

}


BOOST_AUTO_TEST_CASE(TestLoadDescriptorMatcherRadiusOpencvDynamic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


        // load library
    SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

    org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");


    BOOST_TEST(retCode==org::bcom::xpcf::_SUCCESS,"SOLAR ERROR: xpcfComponentManager could not be opened");


    auto component = xpcfComponentManager->create<SolARDescriptorMatcherRadiusOpencv>()->bindTo<api::features::IDescriptorMatcher>();

    BOOST_TEST(component,"SOLAR ERROR: Descriptor Matcher Radius Opencv component could not be created in dynamic mode");

}

BOOST_AUTO_TEST_CASE(TestLoadDescriptorsExtractorAKAZE2OpencvDynamic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


        // load library
    SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

    org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");


    BOOST_TEST(retCode==org::bcom::xpcf::_SUCCESS,"SOLAR ERROR: xpcfComponentManager could not be opened");


    auto component = xpcfComponentManager->create<SolARDescriptorsExtractorAKAZE2Opencv>()->bindTo<api::features::IDescriptorsExtractor>();

    BOOST_TEST(component,"SOLAR ERROR: Descriptors Extractor AKAZE2 Opencv component could not be created in dynamic mode");

}

BOOST_AUTO_TEST_CASE(TestLoadDescriptorsExtractorAKAZEOpencvDynamic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


        // load library
    SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

    org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");


    BOOST_TEST(retCode==org::bcom::xpcf::_SUCCESS,"SOLAR ERROR: xpcfComponentManager could not be opened");


    auto component = xpcfComponentManager->create<SolARDescriptorsExtractorAKAZEOpencv>()->bindTo<api::features::IDescriptorsExtractor>();

    BOOST_TEST(component,"SOLAR ERROR: Descriptors Extractor AKAZE Opencv component could not be created in dynamic mode");

}

BOOST_AUTO_TEST_CASE(TestLoadDescriptorsExtractorORBOpencvDynamic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


        // load library
    SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

    org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");


    BOOST_TEST(retCode==org::bcom::xpcf::_SUCCESS,"SOLAR ERROR: xpcfComponentManager could not be opened");


    auto component = xpcfComponentManager->create<SolARDescriptorsExtractorORBOpencv>()->bindTo<api::features::IDescriptorsExtractor>();

    BOOST_TEST(component,"SOLAR ERROR: Descriptors Extractor ORB Opencv component could not be created in dynamic mode");

}

BOOST_AUTO_TEST_CASE(TestLoadDescriptorsExtractorSBPatternOpencvDynamic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


        // load library
    SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

    org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");


    BOOST_TEST(retCode==org::bcom::xpcf::_SUCCESS,"SOLAR ERROR: xpcfComponentManager could not be opened");


    auto component = xpcfComponentManager->create<SolARDescriptorsExtractorSBPatternOpencv>()->bindTo<api::features::IDescriptorsExtractorSBPattern>();

    BOOST_TEST(component,"SOLAR ERROR: Descriptors Extractor SB Pattern Opencv component could not be created in dynamic mode");

}

BOOST_AUTO_TEST_CASE(TestLoadFundamentalMatrixEstimationOpencvDynamic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


        // load library
    SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

    org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");


    BOOST_TEST(retCode==org::bcom::xpcf::_SUCCESS,"SOLAR ERROR: xpcfComponentManager could not be opened");


    auto component = xpcfComponentManager->create<SolARFundamentalMatrixEstimationOpencv>()->bindTo<api::solver::pose::I2DTransformFinder>();

    BOOST_TEST(component,"SOLAR ERROR: Fundamental Matrix Estimation Opencv component could not be created in dynamic mode");

}

BOOST_AUTO_TEST_CASE(TestLoadGeometricMatchesFilterOpencvDynamic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


        // load library
    SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

    org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");


    BOOST_TEST(retCode==org::bcom::xpcf::_SUCCESS,"SOLAR ERROR: xpcfComponentManager could not be opened");


    auto component = xpcfComponentManager->create<SolARGeometricMatchesFilterOpencv>()->bindTo<api::features::IMatchesFilter>();

    BOOST_TEST(component,"SOLAR ERROR: Geometric Matches Filter Opencv component could not be created in dynamic mode");

}

BOOST_AUTO_TEST_CASE(TestLoadHomographyEstimationOpencvDynamic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


        // load library
    SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

    org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");


    BOOST_TEST(retCode==org::bcom::xpcf::_SUCCESS,"SOLAR ERROR: xpcfComponentManager could not be opened");


    auto component = xpcfComponentManager->create<SolARHomographyEstimationOpencv>()->bindTo<api::solver::pose::I2DTransformFinder>();

    BOOST_TEST(component,"SOLAR ERROR: Homography Estimation Opencv component could not be created in dynamic mode");

}

BOOST_AUTO_TEST_CASE(TestLoadHomographyMatrixDecomposerOpencvDynamic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


        // load library
    SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

    org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");


    BOOST_TEST(retCode==org::bcom::xpcf::_SUCCESS,"SOLAR ERROR: xpcfComponentManager could not be opened");


    auto component = xpcfComponentManager->create<SolARHomographyMatrixDecomposerOpencv>()->bindTo<api::solver::pose::I2DTO3DTransformDecomposer>();

    BOOST_TEST(component,"SOLAR ERROR: Homography Matrix Decomposer Opencv component could not be created in dynamic mode");

}

BOOST_AUTO_TEST_CASE(TestLoadImageConvertorOpencvDynamic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


        // load library
    SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

    org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");


    BOOST_TEST(retCode==org::bcom::xpcf::_SUCCESS,"SOLAR ERROR: xpcfComponentManager could not be opened");


    auto component = xpcfComponentManager->create<SolARImageConvertorOpencv>()->bindTo<api::image::IImageConvertor>();

    BOOST_TEST(component,"SOLAR ERROR: Image Convertor Opencv component could not be created in dynamic mode");

}

BOOST_AUTO_TEST_CASE(TestImageFilterBinaryOpencvCameraDynamic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


        // load library
    SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

    org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");


    BOOST_TEST(retCode==org::bcom::xpcf::_SUCCESS,"SOLAR ERROR: xpcfComponentManager could not be opened");


    auto component = xpcfComponentManager->create<SolARImageFilterBinaryOpencv>()->bindTo<api::image::IImageFilter>();

    BOOST_TEST(component,"SOLAR ERROR: Image Filter Binary Opencv component could not be created in dynamic mode");

}

BOOST_AUTO_TEST_CASE(TestImageFilterAdaptiveBinaryOpencvCameraDynamic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


        // load library
    SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

    org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");


    BOOST_TEST(retCode==org::bcom::xpcf::_SUCCESS,"SOLAR ERROR: xpcfComponentManager could not be opened");


    auto component = xpcfComponentManager->create<SolARImageFilterAdaptiveBinaryOpencv>()->bindTo<api::image::IImageFilter>();

    BOOST_TEST(component,"SOLAR ERROR: Image Filter Adaptive Binary Opencv component could not be created in dynamic mode");

}

BOOST_AUTO_TEST_CASE(TestImageFilterBlurOpencvCameraDynamic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


        // load library
    SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

    org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");


    BOOST_TEST(retCode==org::bcom::xpcf::_SUCCESS,"SOLAR ERROR: xpcfComponentManager could not be opened");


    auto component = xpcfComponentManager->create<SolARImageFilterBlurOpencv>()->bindTo<api::image::IImageFilter>();

    BOOST_TEST(component,"SOLAR ERROR: Image Filter Blur Opencv component could not be created in dynamic mode");

}

BOOST_AUTO_TEST_CASE(TestImageFilterDilateOpencvCameraDynamic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


        // load library
    SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

    org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");


    BOOST_TEST(retCode==org::bcom::xpcf::_SUCCESS,"SOLAR ERROR: xpcfComponentManager could not be opened");


    auto component = xpcfComponentManager->create<SolARImageFilterDilateOpencv>()->bindTo<api::image::IImageFilter>();

    BOOST_TEST(component,"SOLAR ERROR: Image Filter Dilate Opencv component could not be created in dynamic mode");

}

BOOST_AUTO_TEST_CASE(TestImageFilterErodeOpencvCameraDynamic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


        // load library
    SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

    org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");


    BOOST_TEST(retCode==org::bcom::xpcf::_SUCCESS,"SOLAR ERROR: xpcfComponentManager could not be opened");


    auto component = xpcfComponentManager->create<SolARImageFilterErodeOpencv>()->bindTo<api::image::IImageFilter>();

    BOOST_TEST(component,"SOLAR ERROR: Image Filter Erode Opencv component could not be created in dynamic mode");

}


BOOST_AUTO_TEST_CASE(TestLoadImageLoaderOpencvDynamic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


        // load library
    SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

    org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");


    BOOST_TEST(retCode==org::bcom::xpcf::_SUCCESS,"SOLAR ERROR: xpcfComponentManager could not be opened");


    auto component = xpcfComponentManager->create<SolARImageLoaderOpencv>()->bindTo<api::image::IImageLoader>();

    BOOST_TEST(component,"SOLAR ERROR: Image Loader Opencv component could not be created in dynamic mode");

}

BOOST_AUTO_TEST_CASE(TestLoadImageViewerOpencvDynamic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


        // load library
    SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

    org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");


    BOOST_TEST(retCode==org::bcom::xpcf::_SUCCESS,"SOLAR ERROR: xpcfComponentManager could not be opened");


    auto component = xpcfComponentManager->create<SolARImageViewerOpencv>()->bindTo<api::display::IImageViewer>();

    BOOST_TEST(component,"SOLAR ERROR: Image Viewer Opencv component could not be created in dynamic mode");

}

BOOST_AUTO_TEST_CASE(TestLoadKeypointDetectorOpencvDynamic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


        // load library
    SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

    org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");


    BOOST_TEST(retCode==org::bcom::xpcf::_SUCCESS,"SOLAR ERROR: xpcfComponentManager could not be opened");


    auto component = xpcfComponentManager->create<SolARKeypointDetectorOpencv>()->bindTo<api::features::IKeypointDetector>();

    BOOST_TEST(component,"SOLAR ERROR: Keypoint Detector Opencv component could not be created in dynamic mode");

}

BOOST_AUTO_TEST_CASE(TestLoadMarker2DNaturalImageOpencvDynamic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


        // load library
    SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

    org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");


    BOOST_TEST(retCode==org::bcom::xpcf::_SUCCESS,"SOLAR ERROR: xpcfComponentManager could not be opened");


    auto component = xpcfComponentManager->create<SolARMarker2DNaturalImageOpencv>()->bindTo<api::input::files::IMarker2DNaturalImage >();

    BOOST_TEST(component,"SOLAR ERROR: Marker2D Natural Image Opencv component could not be created in dynamic mode");

}

BOOST_AUTO_TEST_CASE(TestLoadMarker2DSquaredBinaryOpencvDynamic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


        // load library
    SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

    org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");


    BOOST_TEST(retCode==org::bcom::xpcf::_SUCCESS,"SOLAR ERROR: xpcfComponentManager could not be opened");


    auto component = xpcfComponentManager->create<SolARMarker2DSquaredBinaryOpencv>()->bindTo<api::input::files::IMarker2DSquaredBinary>();

    BOOST_TEST(component,"SOLAR ERROR: Marker2D Squared Binary Opencv component could not be created in dynamic mode");

}

BOOST_AUTO_TEST_CASE(TestLoadPerspectiveControllerOpencvDynamic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


        // load library
    SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

    org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");


    BOOST_TEST(retCode==org::bcom::xpcf::_SUCCESS,"SOLAR ERROR: xpcfComponentManager could not be opened");


    auto component = xpcfComponentManager->create<SolARPerspectiveControllerOpencv>()->bindTo<api::image::IPerspectiveController>();

    BOOST_TEST(component,"SOLAR ERROR: Perspective Controller Opencv component could not be created in dynamic mode");

}

BOOST_AUTO_TEST_CASE(TestLoadPoseEstimationPnpEPFLDynamic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


        // load library
    SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

    org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");


    BOOST_TEST(retCode==org::bcom::xpcf::_SUCCESS,"SOLAR ERROR: xpcfComponentManager could not be opened");


    auto component = xpcfComponentManager->create<SolARPoseEstimationPnpEPFL>()->bindTo<api::solver::pose::I3DTransformFinder>();

    BOOST_TEST(component,"SOLAR ERROR: Pose Estimation Pnp EPFL component could not be created in dynamic mode");

}

BOOST_AUTO_TEST_CASE(TestLoadPoseEstimationPnpOpencvDynamic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


        // load library
    SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

    org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");


    BOOST_TEST(retCode==org::bcom::xpcf::_SUCCESS,"SOLAR ERROR: xpcfComponentManager could not be opened");


    auto component = xpcfComponentManager->create<SolARPoseEstimationPnpOpencv>()->bindTo<api::solver::pose::I3DTransformFinder>();

    BOOST_TEST(component,"SOLAR ERROR: Pose Estimation Pnp Opencv component could not be created in dynamic mode");

}

BOOST_AUTO_TEST_CASE(TestLoadSideBySideOverlayOpencvDynamic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


        // load library
    SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

    org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");


    BOOST_TEST(retCode==org::bcom::xpcf::_SUCCESS,"SOLAR ERROR: xpcfComponentManager could not be opened");


    auto component = xpcfComponentManager->create<SolARSideBySideOverlayOpencv>()->bindTo<api::display::ISideBySideOverlay>();

    BOOST_TEST(component,"SOLAR ERROR: Side By Side Overlay Opencv component could not be created in dynamic mode");

}

BOOST_AUTO_TEST_CASE(TestLoadSVDFundamentalMatrixDecomposerOpencvDynamic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


        // load library
    SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

    org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");


    BOOST_TEST(retCode==org::bcom::xpcf::_SUCCESS,"SOLAR ERROR: xpcfComponentManager could not be opened");


    auto component = xpcfComponentManager->create<SolARSVDFundamentalMatrixDecomposerOpencv>()->bindTo<api::solver::pose::I2DTO3DTransformDecomposer>();

    BOOST_TEST(component,"SOLAR ERROR: SVD Fundamental Matrix Decomposer Opencv component could not be created in dynamic mode");

}

BOOST_AUTO_TEST_CASE(TestLoadSVDTriangulationOpencvDynamic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


        // load library
    SRef<xpcf::IComponentManager> xpcfComponentManager = xpcf::getComponentManagerInstance();

    org::bcom::xpcf::XPCFErrorCode retCode= xpcfComponentManager->load("$BCOMDEVROOT/.xpcf/SolAR/xpcf_SolARModuleOpenCV_registry.xml");


    BOOST_TEST(retCode==org::bcom::xpcf::_SUCCESS,"SOLAR ERROR: xpcfComponentManager could not be opened");


    auto component = xpcfComponentManager->create<SolARSVDTriangulationOpencv>()->bindTo<api::solver::map::ITriangulator>();

    BOOST_TEST(component,"SOLAR ERROR: SVD Triangulation Opencv component could not be created in dynamic mode");

}



// Static Part


#include "SolAR2DOverlayOpencv.h"
#include "SolAR3DOverlayOpencv.h"
#include "SolARCameraCalibrationOpencv.h"
#include "SolARCameraOpencv.h"
#include "SolARContoursExtractorOpencv.h"
#include "SolARContoursFilterBinaryMarkerOpencv.h"
#include "SolARDescriptorMatcherHammingBruteForceOpencv.h"
#include "SolARDescriptorMatcherKNNOpencv.h"
#include "SolARDescriptorMatcherRadiusOpencv.h"
#include "SolARDescriptorsExtractorAKAZE2Opencv.h"
#include "SolARDescriptorsExtractorAKAZEOpencv.h"
#include "SolARDescriptorsExtractorORBOpencv.h"
#include "SolARDescriptorsExtractorSBPatternOpencv.h"
#include "SolARFundamentalMatrixEstimationOpencv.h"
#include "SolARGeometricMatchesFilterOpencv.h"
#include "SolARHomographyEstimationOpencv.h"
#include "SolARHomographyMatrixDecompositionOpencv.h"
#include "SolARImageConvertorOpencv.h"
#include "SolARImageFilterBinaryOpencv.h"
#include "SolARImageFilterAdaptiveBinaryOpencv.h"
#include "SolARImageFilterBlurOpencv.h"
#include "SolARImageFilterDilateOpencv.h"
#include "SolARImageFilterErodeOpencv.h"
#include "SolARImageLoaderOpencv.h"
#include "SolARImageViewerOpencv.h"
#include "SolARKeypointDetectorOpencv.h"
#include "SolARMarker2DNaturalImageOpencv.h"
#include "SolARMarker2DSquaredBinaryOpencv.h"
#include "SolARPerspectiveControllerOpencv.h"
#include "SolARPoseEstimationPnpEPFL.h"
#include "SolARPoseEstimationPnpOpencv.h"
#include "SolARSideBySideOverlayOpencv.h"
#include "SolARSVDFundamentalMatrixDecomposerOpencv.h"
#include "SolARSVDTriangulationOpencv.h"

#include "SolARCameraOpencv.h"
using namespace SolAR::MODULES::OPENCV;


BOOST_AUTO_TEST_CASE(TestLoad2DOverlayStatic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


    auto component =xpcf::ComponentFactory::createInstance<SolAR2DOverlayOpencv>()->bindTo<api::display::I2DOverlay>();

    BOOST_TEST(component,"SOLAR ERROR: 2DOverlay component could not be created in static mode");

}

BOOST_AUTO_TEST_CASE(TestLoad3DOverlayStatic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


    auto component =xpcf::ComponentFactory::createInstance<SolAR3DOverlayOpencv>()->bindTo<api::display::I3DOverlay>();

    BOOST_TEST(component,"SOLAR ERROR: 3DOverlay component could not be created in static mode");

}

BOOST_AUTO_TEST_CASE(TestLoadCameraCalibrationStatic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


    auto component =xpcf::ComponentFactory::createInstance<SolARCameraCalibrationOpencv>()->bindTo<api::input::devices::ICameraCalibration>();

    BOOST_TEST(component,"SOLAR ERROR: Camera Calibration component could not be created in static mode");

}

BOOST_AUTO_TEST_CASE(TestLoadCameraStatic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


    auto component =xpcf::ComponentFactory::createInstance<SolARCameraOpencv>()->bindTo<input::devices::ICamera>();

    BOOST_TEST(component,"SOLAR ERROR: Camera component could not be created in static mode");

}

BOOST_AUTO_TEST_CASE(TestLoadContoursExtractorStatic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


    auto component =xpcf::ComponentFactory::createInstance<SolARContoursExtractorOpencv>()->bindTo<api::features::IContoursExtractor>();

    BOOST_TEST(component,"SOLAR ERROR: Contours Extractor component could not be created in static mode");

}

BOOST_AUTO_TEST_CASE(TestContoursFilterStatic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


    auto component =xpcf::ComponentFactory::createInstance<SolARContoursFilterBinaryMarkerOpencv>()->bindTo<api::features::IContoursFilter>();

    BOOST_TEST(component,"SOLAR ERROR: Contours Filter component could not be created in static mode");

}

BOOST_AUTO_TEST_CASE(TestLoadDescriptorMatcherHammingBruteForceOpencvStatic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


    auto component =xpcf::ComponentFactory::createInstance<SolARDescriptorMatcherHammingBruteForceOpencv>()->bindTo<api::features::IDescriptorMatcher>();

    BOOST_TEST(component,"SOLAR ERROR: Descriptor Matcher Hamming Brute Force Opencv component could not be created in static mode");

}


BOOST_AUTO_TEST_CASE(TestLoadDescriptorMatcherKNNOpencvStatic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif

    auto component =xpcf::ComponentFactory::createInstance<SolARDescriptorMatcherKNNOpencv>()->bindTo<api::features::IDescriptorMatcher>();

    BOOST_TEST(component,"SOLAR ERROR: Descriptor Matcher KNN Opencv component could not be created in static mode");

}


BOOST_AUTO_TEST_CASE(TestLoadDescriptorMatcherRadiusOpencvStatic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


    auto component =xpcf::ComponentFactory::createInstance<SolARDescriptorMatcherRadiusOpencv>()->bindTo<api::features::IDescriptorMatcher>();

    BOOST_TEST(component,"SOLAR ERROR: Descriptor Matcher Radius Opencv component could not be created in static mode");

}

BOOST_AUTO_TEST_CASE(TestLoadDescriptorsExtractorAKAZE2OpencvStatic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


    auto component =xpcf::ComponentFactory::createInstance<SolARDescriptorsExtractorAKAZE2Opencv>()->bindTo<api::features::IDescriptorsExtractor>();

    BOOST_TEST(component,"SOLAR ERROR: Descriptors Extractor AKAZE2 Opencv component could not be created in static mode");

}

BOOST_AUTO_TEST_CASE(TestLoadDescriptorsExtractorAKAZEOpencvStatic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


    auto component =xpcf::ComponentFactory::createInstance<SolARDescriptorsExtractorAKAZEOpencv>()->bindTo<api::features::IDescriptorsExtractor>();

    BOOST_TEST(component,"SOLAR ERROR: Descriptors Extractor AKAZE Opencv component could not be created in static mode");

}

BOOST_AUTO_TEST_CASE(TestLoadDescriptorsExtractorORBOpencvStatic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


    auto component =xpcf::ComponentFactory::createInstance<SolARDescriptorsExtractorORBOpencv>()->bindTo<api::features::IDescriptorsExtractor>();

    BOOST_TEST(component,"SOLAR ERROR: Descriptors Extractor ORB Opencv component could not be created in static mode");

}

BOOST_AUTO_TEST_CASE(TestLoadDescriptorsExtractorSBPatternOpencvStatic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


    auto component =xpcf::ComponentFactory::createInstance<SolARDescriptorsExtractorSBPatternOpencv>()->bindTo<api::features::IDescriptorsExtractorSBPattern>();

    BOOST_TEST(component,"SOLAR ERROR: Descriptors Extractor SB Pattern Opencv component could not be created in static mode");

}

BOOST_AUTO_TEST_CASE(TestLoadFundamentalMatrixEstimationOpencvStatic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


    auto component =xpcf::ComponentFactory::createInstance<SolARFundamentalMatrixEstimationOpencv>()->bindTo<api::solver::pose::I2DTransformFinder>();

    BOOST_TEST(component,"SOLAR ERROR: Fundamental Matrix Estimation Opencv component could not be created in static mode");

}

BOOST_AUTO_TEST_CASE(TestLoadGeometricMatchesFilterOpencvStatic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


    auto component =xpcf::ComponentFactory::createInstance<SolARGeometricMatchesFilterOpencv>()->bindTo<api::features::IMatchesFilter>();

    BOOST_TEST(component,"SOLAR ERROR: Geometric Matches Filter Opencv component could not be created in static mode");

}

BOOST_AUTO_TEST_CASE(TestLoadHomographyEstimationOpencvStatic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


    auto component =xpcf::ComponentFactory::createInstance<SolARHomographyEstimationOpencv>()->bindTo<api::solver::pose::I2DTransformFinder>();

    BOOST_TEST(component,"SOLAR ERROR: Homography Estimation Opencv component could not be created in static mode");

}

BOOST_AUTO_TEST_CASE(TestLoadHomographyMatrixDecomposerOpencvStatic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


    auto component =xpcf::ComponentFactory::createInstance<SolARHomographyMatrixDecomposerOpencv>()->bindTo<api::solver::pose::I2DTO3DTransformDecomposer>();

    BOOST_TEST(component,"SOLAR ERROR: Homography Matrix Decomposer Opencv component could not be created in static mode");

}

BOOST_AUTO_TEST_CASE(TestLoadImageConvertorOpencvStatic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


    auto component =xpcf::ComponentFactory::createInstance<SolARImageConvertorOpencv>()->bindTo<api::image::IImageConvertor>();

    BOOST_TEST(component,"SOLAR ERROR: Image Convertor Opencv component could not be created in static mode");

}

BOOST_AUTO_TEST_CASE(TestImageFilterBinaryOpencvCameraStatic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


    auto component =xpcf::ComponentFactory::createInstance<SolARImageFilterBinaryOpencv>()->bindTo<api::image::IImageFilter>();

    BOOST_TEST(component,"SOLAR ERROR: Image Filter Binary Opencv component could not be created in static mode");

}

BOOST_AUTO_TEST_CASE(TestImageFilterAdaptiveBinaryOpencvCameraStatic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


    auto component =xpcf::ComponentFactory::createInstance<SolARImageFilterAdaptiveBinaryOpencv>()->bindTo<api::image::IImageFilter>();

    BOOST_TEST(component,"SOLAR ERROR: Image Filter Adaptive Binary Opencv component could not be created in static mode");

}

BOOST_AUTO_TEST_CASE(TestImageFilterBlurOpencvCameraStatic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


    auto component =xpcf::ComponentFactory::createInstance<SolARImageFilterBlurOpencv>()->bindTo<api::image::IImageFilter>();

    BOOST_TEST(component,"SOLAR ERROR: Image Filter Blur Opencv component could not be created in static mode");

}

BOOST_AUTO_TEST_CASE(TestImageFilterDilateOpencvCameraStatic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


    auto component =xpcf::ComponentFactory::createInstance<SolARImageFilterDilateOpencv>()->bindTo<api::image::IImageFilter>();

    BOOST_TEST(component,"SOLAR ERROR: Image Filter Dilate Opencv component could not be created in static mode");

}

BOOST_AUTO_TEST_CASE(TestImageFilterErodeOpencvCameraStatic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


    auto component =xpcf::ComponentFactory::createInstance<SolARImageFilterErodeOpencv>()->bindTo<api::image::IImageFilter>();

    BOOST_TEST(component,"SOLAR ERROR: Image Filter Erode Opencv component could not be created in static mode");

}

BOOST_AUTO_TEST_CASE(TestLoadImageLoaderOpencvStatic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


    auto component =xpcf::ComponentFactory::createInstance<SolARImageLoaderOpencv>()->bindTo<api::image::IImageLoader>();

    BOOST_TEST(component,"SOLAR ERROR: Image Loader Opencv component could not be created in static mode");

}

BOOST_AUTO_TEST_CASE(TestLoadImageViewerOpencvStatic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


    auto component =xpcf::ComponentFactory::createInstance<SolARImageViewerOpencv>()->bindTo<api::display::IImageViewer>();

    BOOST_TEST(component,"SOLAR ERROR: Image Viewer Opencv component could not be created in static mode");

}

BOOST_AUTO_TEST_CASE(TestLoadKeypointDetectorOpencvStatic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


    auto component =xpcf::ComponentFactory::createInstance<SolARKeypointDetectorOpencv>()->bindTo<api::features::IKeypointDetector>();

    BOOST_TEST(component,"SOLAR ERROR: Keypoint Detector Opencv component could not be created in static mode");

}

BOOST_AUTO_TEST_CASE(TestLoadMarker2DNaturalImageOpencvStatic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


    auto component =xpcf::ComponentFactory::createInstance<SolARMarker2DNaturalImageOpencv>()->bindTo<api::input::files::IMarker2DNaturalImage >();

    BOOST_TEST(component,"SOLAR ERROR: Marker2D Natural Image Opencv component could not be created in static mode");

}

BOOST_AUTO_TEST_CASE(TestLoadMarker2DSquaredBinaryOpencvStatic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


    auto component =xpcf::ComponentFactory::createInstance<SolARMarker2DSquaredBinaryOpencv>()->bindTo<api::input::files::IMarker2DSquaredBinary>();

    BOOST_TEST(component,"SOLAR ERROR: Marker2D Squared Binary Opencv component could not be created in static mode");

}

BOOST_AUTO_TEST_CASE(TestLoadPerspectiveControllerOpencvStatic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


    auto component =xpcf::ComponentFactory::createInstance<SolARPerspectiveControllerOpencv>()->bindTo<api::image::IPerspectiveController>();

    BOOST_TEST(component,"SOLAR ERROR: Perspective Controller Opencv component could not be created in static mode");

}

BOOST_AUTO_TEST_CASE(TestLoadPoseEstimationPnpEPFLStatic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


    auto component =xpcf::ComponentFactory::createInstance<SolARPoseEstimationPnpEPFL>()->bindTo<api::solver::pose::I3DTransformFinder>();

    BOOST_TEST(component,"SOLAR ERROR: Pose Estimation Pnp EPFL component could not be created in static mode");

}

BOOST_AUTO_TEST_CASE(TestLoadPoseEstimationPnpOpencvStatic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


    auto component =xpcf::ComponentFactory::createInstance<SolARPoseEstimationPnpOpencv>()->bindTo<api::solver::pose::I3DTransformFinder>();

    BOOST_TEST(component,"SOLAR ERROR: Pose Estimation Pnp Opencv component could not be created in static mode");

}

BOOST_AUTO_TEST_CASE(TestLoadSideBySideOverlayOpencvStatic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


    auto component =xpcf::ComponentFactory::createInstance<SolARSideBySideOverlayOpencv>()->bindTo<api::display::ISideBySideOverlay>();

    BOOST_TEST(component,"SOLAR ERROR: Side By Side Overlay Opencv component could not be created in static mode");

}

BOOST_AUTO_TEST_CASE(TestLoadSVDFundamentalMatrixDecomposerOpencvStatic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


    auto component =xpcf::ComponentFactory::createInstance<SolARSVDFundamentalMatrixDecomposerOpencv>()->bindTo<api::solver::pose::I2DTO3DTransformDecomposer>();

    BOOST_TEST(component,"SOLAR ERROR: SVD Fundamental Matrix Decomposer Opencv component could not be created in static mode");

}

BOOST_AUTO_TEST_CASE(TestLoadSVDTriangulationOpencvStatic)
{

#if NDEBUG
    boost::log::core::get()->set_logging_enabled(false);
#endif


    auto component =xpcf::ComponentFactory::createInstance<SolARSVDTriangulationOpencv>()->bindTo<api::solver::map::ITriangulator>();

    BOOST_TEST(component,"SOLAR ERROR: SVD Triangulation Opencv component could not be created in static mode");

}



