cmake_minimum_required(VERSION 3.7.2)

##################################################
project("ComponentLoading")
set (SOURCES SolARComponentLoadingUnitTests.cpp)
##################################################

# various macros
include("$ENV{BCOMDEVROOT}/bcomBuild/SolARFramework/solarmacros.cmake")
# config setup
setup()
# process packagedependencies.txt
processPackagedependencies()

# define the list of files to copy to build directory

set(FILES_TO_COPY
	$ENV{BCOMDEVROOT}/thirdParties/opencv/${OPENCV_VERSION}/lib/x86_64/shared/${BUILDCONFIG}/${LIBPREFIX}opencv_world${OPENCVVERSIONSUFFIX}.${LIBEXTENSION}*
	$ENV{BCOMDEVROOT}/thirdParties/boost/${BOOST_VERSION}/lib/x86_64/shared/${BUILDCONFIG}/${LIBPREFIX}boost_filesystem.${LIBEXTENSION}*
	$ENV{BCOMDEVROOT}/thirdParties/boost/${BOOST_VERSION}/lib/x86_64/shared/${BUILDCONFIG}/${LIBPREFIX}boost_system.${LIBEXTENSION}*
	$ENV{BCOMDEVROOT}/thirdParties/boost/${BOOST_VERSION}/lib/x86_64/shared/${BUILDCONFIG}/${LIBPREFIX}boost_timer.${LIBEXTENSION}*
	$ENV{BCOMDEVROOT}/thirdParties/boost/${BOOST_VERSION}/lib/x86_64/shared/${BUILDCONFIG}/${LIBPREFIX}boost_log.${LIBEXTENSION}*
	$ENV{BCOMDEVROOT}/thirdParties/boost/${BOOST_VERSION}/lib/x86_64/shared/${BUILDCONFIG}/${LIBPREFIX}boost_chrono.${LIBEXTENSION}*
	$ENV{BCOMDEVROOT}/thirdParties/boost/${BOOST_VERSION}/lib/x86_64/shared/${BUILDCONFIG}/${LIBPREFIX}boost_thread.${LIBEXTENSION}*
	$ENV{BCOMDEVROOT}/thirdParties/boost/${BOOST_VERSION}/lib/x86_64/shared/${BUILDCONFIG}/${LIBPREFIX}boost_date_time.${LIBEXTENSION}*
	$ENV{BCOMDEVROOT}/thirdParties/boost/${BOOST_VERSION}/lib/x86_64/shared/${BUILDCONFIG}/${LIBPREFIX}boost_context.${LIBEXTENSION}*
	$ENV{BCOMDEVROOT}/thirdParties/boost/${BOOST_VERSION}/lib/x86_64/shared/${BUILDCONFIG}/${LIBPREFIX}boost_fiber.${LIBEXTENSION}*
	$ENV{BCOMDEVROOT}/thirdParties/boost/${BOOST_VERSION}/lib/x86_64/shared/${BUILDCONFIG}/${LIBPREFIX}boost_unit_test_framework.${LIBEXTENSION}*

	#$ENV{BCOMDEVROOT}/thirdParties/ceres/${CERES_VERSION}/lib/x86_64/shared/${BUILDCONFIG}/${LIBPREFIX}ceres.${LIBEXTENSION}*
	#$ENV{BCOMDEVROOT}/thirdParties/glog/${GLOG_VERSION}/lib/x86_64/shared/${BUILDCONFIG}/${LIBPREFIX}glog.${LIBEXTENSION}*
	#$ENV{BCOMDEVROOT}/thirdParties/gflags/${GFLAGS_VERSION}/lib/x86_64/shared/${BUILDCONFIG}/${LIBPREFIX}gflags.${LIBEXTENSION}*
    $ENV{BCOMDEVROOT}/bcomBuild/SolARFramework/${SOLARFRAMEWORK_VERSION}/lib/x86_64/shared/${BUILDCONFIG}/${LIBPREFIX}SolARFramework.${LIBEXTENSION}
	$ENV{BCOMDEVROOT}/thirdParties/xpcf/${XPCF_VERSION}/lib/x86_64/shared/${BUILDCONFIG}/${LIBPREFIX}xpcf.${LIBEXTENSION}
	)
# define targets (library, install and uninstall)
defineTargets("executable" "${FILES_TO_COPY}")

