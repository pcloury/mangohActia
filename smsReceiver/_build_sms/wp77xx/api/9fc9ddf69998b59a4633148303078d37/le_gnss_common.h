
/*
 * ====================== WARNING ======================
 *
 * THE CONTENTS OF THIS FILE HAVE BEEN AUTO-GENERATED.
 * DO NOT MODIFY IN ANY WAY.
 *
 * ====================== WARNING ======================
 */
#ifndef LE_GNSS_COMMON_H_INCLUDE_GUARD
#define LE_GNSS_COMMON_H_INCLUDE_GUARD


#include "legato.h"

#define IFGEN_LE_GNSS_PROTOCOL_ID "b0b744f34d12d4936994c147779dda34"
#define IFGEN_LE_GNSS_MSG_SIZE 2015



//--------------------------------------------------------------------------------------------------
/**
 * Maximum length of the SUP Server URL string.
 */
//--------------------------------------------------------------------------------------------------
#define LE_GNSS_SUPL_SERVER_URL_MAX_LEN 256

//--------------------------------------------------------------------------------------------------
/**
 * Maximum length of the SUP Server URL string.
 * One extra byte is added for the null character.
 */
//--------------------------------------------------------------------------------------------------
#define LE_GNSS_SUPL_SERVER_URL_MAX_BYTES 257

//--------------------------------------------------------------------------------------------------
/**
 * Maximum SUPL certificate size.
 */
//--------------------------------------------------------------------------------------------------
#define LE_GNSS_SUPL_CERTIFICATE_MAX_LEN 2000

//--------------------------------------------------------------------------------------------------
/**
 * Maximum SUPL certificate string size.
 * One extra byte is added for the null character.
 */
//--------------------------------------------------------------------------------------------------
#define LE_GNSS_SUPL_CERTIFICATE_MAX_BYTES 2001

//--------------------------------------------------------------------------------------------------
/**
 * Define the maximum length of the Satellites Vehicle information list
 */
//--------------------------------------------------------------------------------------------------
#define LE_GNSS_SV_INFO_MAX_LEN 80

//--------------------------------------------------------------------------------------------------
/**
 * Define the maximal bit mask for enabled NMEA sentences
 *
 * @note This maximal value should be coherent with @ref le_gnss_NmeaBitMask_t
 */
//--------------------------------------------------------------------------------------------------
#define LE_GNSS_NMEA_SENTENCES_MAX 15728639

//--------------------------------------------------------------------------------------------------
/**
 * @deprecated LE_GNSS_NMEA_MASK_PQXFI is deprecated. LE_GNSS_NMEA_MASK_PTYPE is to be used instead.
 * Setting LE_GNSS_NMEA_MASK_PTYPE will also set LE_GNSS_NMEA_MASK_PQXFI.
 * LE_GNSS_NMEA_MASK_PTYPE supports all Proprietary type masks: PQXFI, PQGSA and PQGSV.
 */
//--------------------------------------------------------------------------------------------------
#define LE_GNSS_NMEA_MASK_PQXFI 16384

//--------------------------------------------------------------------------------------------------
/**
 * Define the maximal degree for the minimal elevation
 */
//--------------------------------------------------------------------------------------------------
#define LE_GNSS_MIN_ELEVATION_MAX_DEGREE 90

//--------------------------------------------------------------------------------------------------
/**
 * Satellite Vehicle (SV) ID to PRN offset definitions
 *
 * @note SV ID is given both in le_gnss_GetSatellitesInfo() API and NMEA flow. Its corresponding
 *       PRN code can be computed adding the following offset according to its constellation.
 */
//--------------------------------------------------------------------------------------------------
#define LE_GNSS_PRN_OFFSET_GPS 0

//--------------------------------------------------------------------------------------------------
/**
 */
//--------------------------------------------------------------------------------------------------
#define LE_GNSS_PRN_OFFSET_SBAS 87

//--------------------------------------------------------------------------------------------------
/**
 */
//--------------------------------------------------------------------------------------------------
#define LE_GNSS_PRN_OFFSET_GLONASS -64

//--------------------------------------------------------------------------------------------------
/**
 */
//--------------------------------------------------------------------------------------------------
#define LE_GNSS_PRN_OFFSET_GALILEO -300

//--------------------------------------------------------------------------------------------------
/**
 */
//--------------------------------------------------------------------------------------------------
#define LE_GNSS_PRN_OFFSET_BEIDOU -200

//--------------------------------------------------------------------------------------------------
/**
 */
//--------------------------------------------------------------------------------------------------
#define LE_GNSS_PRN_OFFSET_QZSS 0

//--------------------------------------------------------------------------------------------------
/**
 *  Reference type for dealing with GNSS position samples.
 */
//--------------------------------------------------------------------------------------------------
typedef struct le_gnss_Sample* le_gnss_SampleRef_t;


//--------------------------------------------------------------------------------------------------
/**
 * Enumeration for GNSS device state
 */
//--------------------------------------------------------------------------------------------------
typedef enum
{
    LE_GNSS_STATE_UNINITIALIZED = 0,
        ///< The GNSS device is not initialized
    LE_GNSS_STATE_READY = 1,
        ///< The GNSS device is ready
    LE_GNSS_STATE_ACTIVE = 2,
        ///< The GNSS device is active
    LE_GNSS_STATE_DISABLED = 3,
        ///< The GNSS device is disabled
    LE_GNSS_STATE_MAX = 4
        ///< Do not use
}
le_gnss_State_t;


//--------------------------------------------------------------------------------------------------
/**
 *  GNSS fix position states.
 */
//--------------------------------------------------------------------------------------------------
typedef enum
{
    LE_GNSS_STATE_FIX_NO_POS = 0,
        ///< The GNSS fix position is not fixed.
    LE_GNSS_STATE_FIX_2D = 1,
        ///< 2-Dimensional position fix.
    LE_GNSS_STATE_FIX_3D = 2,
        ///< 3-Dimensional position fix.
    LE_GNSS_STATE_FIX_ESTIMATED = 3
        ///< Estimated (i.e. forward predicted) position fix.
}
le_gnss_FixState_t;


//--------------------------------------------------------------------------------------------------
/**
 *  Resolutions values.
 */
//--------------------------------------------------------------------------------------------------
typedef enum
{
    LE_GNSS_RES_ZERO_DECIMAL = 0,
        ///< Resolution of 0 decimal place.
    LE_GNSS_RES_ONE_DECIMAL = 1,
        ///< Resolution of 1 decimal place.
    LE_GNSS_RES_TWO_DECIMAL = 2,
        ///< Resolution of 2 decimal places.
    LE_GNSS_RES_THREE_DECIMAL = 3,
        ///< Resolution of 3 decimal places.
    LE_GNSS_RES_UNKNOWN = 4
        ///< Unknown resolution.
}
le_gnss_Resolution_t;


//--------------------------------------------------------------------------------------------------
/**
 **  Data types.
 */
//--------------------------------------------------------------------------------------------------
typedef enum
{
    LE_GNSS_DATA_VACCURACY = 0,
        ///< Vertical accuracy data.
    LE_GNSS_DATA_VSPEEDACCURACY = 1,
        ///< Vertical speed accuracy data.
    LE_GNSS_DATA_HSPEEDACCURACY = 2,
        ///< Horizontal speed accuracy data.
    LE_GNSS_DATA_UNKNOWN = 3
        ///< Unknown data type.
}
le_gnss_DataType_t;


//--------------------------------------------------------------------------------------------------
/**
 *  SBAS constellation category
 */
//--------------------------------------------------------------------------------------------------
typedef enum
{
    LE_GNSS_SBAS_EGNOS = 0,
        ///< Satellite Vehicle of Satellite-based augmentation system
        ///< (SBAS) EGNOS constellation.
    LE_GNSS_SBAS_WAAS = 1,
        ///< Satellite Vehicle of Satellite-based augmentation system
        ///< (SBAS) WAAS constellation.
    LE_GNSS_SBAS_GAGAN = 2,
        ///< Satellite Vehicle of Satellite-based augmentation system
        ///< (SBAS) GAGAN constellation.
    LE_GNSS_SBAS_MSAS = 3,
        ///< Satellite Vehicle of Satellite-based augmentation system
        ///< (SBAS) MSAS constellation.
    LE_GNSS_SBAS_SDCM = 4,
        ///< Satellite Vehicle of Satellite-based augmentation system
        ///< (SBAS) SDCM constellation.
    LE_GNSS_SBAS_UNKNOWN = 5
        ///< Satellite Vehicle of Satellite-based augmentation system
        ///< (SBAS) unknown constellation.
}
le_gnss_SbasConstellationCategory_t;


//--------------------------------------------------------------------------------------------------
/**
 *  GNSS constellation type.
 */
//--------------------------------------------------------------------------------------------------
typedef enum
{
    LE_GNSS_SV_CONSTELLATION_UNDEFINED = 0,
        ///< GNSS constellation field not defined.
    LE_GNSS_SV_CONSTELLATION_GPS = 1,
        ///< Satellite Vehicle of GPS constellation.
        ///< North American satellite navigation system
    LE_GNSS_SV_CONSTELLATION_SBAS = 2,
        ///< Satellite Vehicle of SBAS constellation.
        ///< Satellite-based augmentation system
    LE_GNSS_SV_CONSTELLATION_GLONASS = 3,
        ///< Satellite Vehicle of Glonass constellation.
        ///< Russian satellite navigation system
    LE_GNSS_SV_CONSTELLATION_GALILEO = 4,
        ///< Satellite Vehicle of Galileo constellation.
        ///< European Union satellite navigation system
    LE_GNSS_SV_CONSTELLATION_BEIDOU = 5,
        ///< Satellite Vehicle of Beidou constellation.
        ///< Chinese satellite navigation system
    LE_GNSS_SV_CONSTELLATION_QZSS = 6,
        ///< Satellite Vehicle of QZSS constellation.
        ///< Japanese satellite navigation system
    LE_GNSS_SV_CONSTELLATION_MAX = 7
        ///< Maximum value.
}
le_gnss_Constellation_t;


//--------------------------------------------------------------------------------------------------
/**
 * Assisted-GNSS mode
 */
//--------------------------------------------------------------------------------------------------
typedef enum
{
    LE_GNSS_STANDALONE_MODE = 0,
        ///< Standalone mode.
    LE_GNSS_MS_BASED_MODE = 1,
        ///< MS-Based mode.
    LE_GNSS_MS_ASSISTED_MODE = 2
        ///< MS-Assisted mode.
}
le_gnss_AssistedMode_t;


//--------------------------------------------------------------------------------------------------
/**
 * Dilution of precision type
 */
//--------------------------------------------------------------------------------------------------
typedef enum
{
    LE_GNSS_PDOP = 0,
        ///< Position dilution of precision.
    LE_GNSS_HDOP = 1,
        ///< Horizontal dilution of precision.
    LE_GNSS_VDOP = 2,
        ///< Vertical dilution of precision.
    LE_GNSS_GDOP = 3,
        ///< Geometric dilution of precision.
    LE_GNSS_TDOP = 4,
        ///< Time dilution of precision.
    LE_GNSS_DOP_LAST = 5
        ///<
}
le_gnss_DopType_t;


//--------------------------------------------------------------------------------------------------
/**
 * GNSS constellation area type
 */
//--------------------------------------------------------------------------------------------------
typedef enum
{
    LE_GNSS_UNSET_AREA = 0,
        ///< Unset area.
    LE_GNSS_WORLDWIDE_AREA = 1,
        ///< Worldwide area.
    LE_GNSS_OUTSIDE_US_AREA = 2
        ///< Outside US area.
}
le_gnss_ConstellationArea_t;


//--------------------------------------------------------------------------------------------------
/**
 * GNSS constellation Bit Mask (8 bits) indicating the GNSS constellation(s)
 * used in solution.
 *
 */
//--------------------------------------------------------------------------------------------------/// GPS constellation used in solution.
/// North American satellite navigation system
#define LE_GNSS_CONSTELLATION_GPS 0x1/// GLONASS constellation used in solution.
/// Russian satellite navigation system
#define LE_GNSS_CONSTELLATION_GLONASS 0x2/// BEIDOU constellation used in solution.
/// Chinese satellite navigation system
#define LE_GNSS_CONSTELLATION_BEIDOU 0x4/// GALILEO constellation used in solution.
/// European Union satellite navigation system
#define LE_GNSS_CONSTELLATION_GALILEO 0x8/// SBAS constellation used in solution.
#define LE_GNSS_CONSTELLATION_SBAS 0x10/// QZSS constellation used in solution.
/// Japanese satellite navigation system
#define LE_GNSS_CONSTELLATION_QZSS 0x20
typedef uint32_t le_gnss_ConstellationBitMask_t;


//--------------------------------------------------------------------------------------------------
/**
 * NMEA sentences Bit Mask indicating the NMEA sentences enabled in the NMEA flow.
 *
 * @warning The supported NMEA sentences depend on the platform. Please refer to your platform
 * documentation for further details.
 *
 * @note The bit mask values should be coherent with @ref LE_GNSS_NMEA_SENTENCES_MAX
 */
//--------------------------------------------------------------------------------------------------/// GPGGA type enabled: GPS fix data.
#define LE_GNSS_NMEA_MASK_GPGGA 0x1/// GPGSA type enabled: GPS DOP and active satellites.
#define LE_GNSS_NMEA_MASK_GPGSA 0x2/// GPGSV type enabled: GPS satellites in view.
#define LE_GNSS_NMEA_MASK_GPGSV 0x4/// GPRMC type enabled: GPS recommended minimum data.
#define LE_GNSS_NMEA_MASK_GPRMC 0x8/// GPVTG type enabled: GPS vector track and speed over the ground.
#define LE_GNSS_NMEA_MASK_GPVTG 0x10/// GLGSV type enabled: GLONASS satellites in view.
#define LE_GNSS_NMEA_MASK_GLGSV 0x20/// GNGNS type enabled: GNSS fix data.
#define LE_GNSS_NMEA_MASK_GNGNS 0x40/// GNGSA type enabled: GNSS DOP and active satellites.
#define LE_GNSS_NMEA_MASK_GNGSA 0x80/// GAGGA type enabled: Galileo fix data.
#define LE_GNSS_NMEA_MASK_GAGGA 0x100/// GAGSA type enabled: Galileo DOP and active satellites.
#define LE_GNSS_NMEA_MASK_GAGSA 0x200/// GAGSV type enabled: Galileo satellites in view.
#define LE_GNSS_NMEA_MASK_GAGSV 0x400/// GARMC type enabled: Galileo recommended minimum data.
#define LE_GNSS_NMEA_MASK_GARMC 0x800/// GAVTG type enabled: Galileo vector track and speed over the ground.
#define LE_GNSS_NMEA_MASK_GAVTG 0x1000/// PSTIS type enabled: GPS session start indication.
#define LE_GNSS_NMEA_MASK_PSTIS 0x2000///
#define LE_GNSS_NMEA_MASK_REMOVED 0x4000/// PTYPE type enabled: Proprietary Type mask.
#define LE_GNSS_NMEA_MASK_PTYPE 0x8000/// GPGRS type enabled: GPS Range residuals.
#define LE_GNSS_NMEA_MASK_GPGRS 0x10000/// GPGLL type enabled: GPS Geographic position, latitude / longitude.
#define LE_GNSS_NMEA_MASK_GPGLL 0x20000/// DEBUG type enabled: Debug NMEA indication.
#define LE_GNSS_NMEA_MASK_DEBUG 0x40000/// GPDTM type enabled: Local geodetic datum and datum offset from a
#define LE_GNSS_NMEA_MASK_GPDTM 0x80000/// GAGNS type enabled: Fix data for Galileo.
#define LE_GNSS_NMEA_MASK_GAGNS 0x100000/// GPGNS type enabled: Fix data for GPS.
#define LE_GNSS_NMEA_MASK_GPGNS 0x200000/// GPGST type enabled: Position Error statistics for GPS.
#define LE_GNSS_NMEA_MASK_GPGST 0x400000/// GPZDA type enabled: UTC day, month, year, and local time zone offset.
#define LE_GNSS_NMEA_MASK_GPZDA 0x800000
typedef uint32_t le_gnss_NmeaBitMask_t;


//--------------------------------------------------------------------------------------------------
/**
 *  Coordinate system
 */
//--------------------------------------------------------------------------------------------------
typedef enum
{
    LE_GNSS_COORDINATE_SYSTEM_WGS84 = 0,
        ///< Coordinate system WGS84.
    LE_GNSS_COORDINATE_SYSTEM_PZ90 = 1,
        ///< Coordinate system PZ90.
    LE_GNSS_COORDINATE_SYSTEM_MAX = 2
        ///< Maximum value.
}
le_gnss_CoordinateSystem_t;


//--------------------------------------------------------------------------------------------------
/**
 **  Location data types
 */
//--------------------------------------------------------------------------------------------------
typedef enum
{
    LE_GNSS_POS_LATITUDE = 0,
        ///< Latitude data position.
    LE_GNSS_POS_LONGITUDE = 1,
        ///< Longitude data position.
    LE_GNSS_POS_ALTITUDE = 2,
        ///< Altitude data position.
    LE_GNSS_POS_MAX = 3
        ///< Maximum value.
}
le_gnss_LocationDataType_t;


//--------------------------------------------------------------------------------------------------
/**
 * Type of GNSS start.
 */
//--------------------------------------------------------------------------------------------------
typedef enum
{
    LE_GNSS_HOT_START = 0,
        ///< Hot start.
    LE_GNSS_WARM_START = 1,
        ///< Warm start.
    LE_GNSS_COLD_START = 2,
        ///< Cold start.
    LE_GNSS_FACTORY_START = 3,
        ///< Factory start.
    LE_GNSS_UNKNOWN_START = 4
        ///< Unknown start.
}
le_gnss_StartMode_t;


//--------------------------------------------------------------------------------------------------
/**
 * Reference type used by Add/Remove functions for EVENT 'le_gnss_Position'
 */
//--------------------------------------------------------------------------------------------------
typedef struct le_gnss_PositionHandler* le_gnss_PositionHandlerRef_t;


//--------------------------------------------------------------------------------------------------
/**
 * Handler for position information.
 *
 */
//--------------------------------------------------------------------------------------------------
typedef void (*le_gnss_PositionHandlerFunc_t)
(
        le_gnss_SampleRef_t positionSampleRef,
        ///< Position's sample reference
        void* contextPtr
        ///<
);


//--------------------------------------------------------------------------------------------------
/**
 * Get if this client bound locally.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED bool ifgen_le_gnss_HasLocalBinding
(
    void
);


//--------------------------------------------------------------------------------------------------
/**
 * Init data that is common across all threads
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED void ifgen_le_gnss_InitCommonData
(
    void
);


//--------------------------------------------------------------------------------------------------
/**
 * Perform common initialization and open a session
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_OpenSession
(
    le_msg_SessionRef_t _ifgen_sessionRef,
    bool isBlocking
);

//--------------------------------------------------------------------------------------------------
/**
 * Set the GNSS constellation bit mask
 *
 * @return
 *  - LE_FAULT         The function failed.
 *  - LE_UNSUPPORTED   If the request is not supported.
 *  - LE_NOT_PERMITTED If the GNSS device is not initialized, disabled or active.
 *  - LE_OK            The function succeeded.
 *
 * @warning Some constellation types are unsupported depending on the platform. Please refer to
 *          @ref platformConstraintsGnss_ConstellationType section for full details.
 *
 * @warning The settings are platform dependent. Please refer to
 *          @ref platformConstraintsGnss_SettingConfiguration section for full details.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_SetConstellation
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        le_gnss_ConstellationBitMask_t constellationMask
        ///< [IN] GNSS constellation used in solution.
);

//--------------------------------------------------------------------------------------------------
/**
 * Get the GNSS constellation bit mask
 *
 * @return
 *  - LE_OK on success
 *  - LE_FAULT on failure
 *
 * @note If the caller is passing a null pointer into this function, it is a fatal error, the
 *       function will not return.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_GetConstellation
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        le_gnss_ConstellationBitMask_t* constellationMaskPtr
        ///< [OUT] GNSS constellation used in solution.
);

//--------------------------------------------------------------------------------------------------
/**
 * Set the area for the GNSS constellation
 *
 * @return
 *  - LE_OK            The function succeeded.
 *  - LE_FAULT         The function failed.
 *  - LE_UNSUPPORTED   If the request is not supported.
 *  - LE_NOT_PERMITTED If the GNSS device is not initialized, disabled or active.
 *  - LE_BAD_PARAMETER Invalid constellation area.
 *
 * @warning The settings are platform dependent. Please refer to
 *          @ref platformConstraintsGnss_SettingConfiguration section for full details.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_SetConstellationArea
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        le_gnss_Constellation_t satConstellation,
        ///< [IN] GNSS constellation type.
        le_gnss_ConstellationArea_t constellationArea
        ///< [IN] GNSS constellation area.
);

//--------------------------------------------------------------------------------------------------
/**
 * Get the area for the GNSS constellation
 *
 * @return
 *  - LE_OK            On success
 *  - LE_FAULT         On failure
 *  - LE_UNSUPPORTED   Request not supported
 *  - LE_NOT_PERMITTED If the GNSS device is not initialized, disabled or active.
 *
 * @note If the caller is passing a null pointer into this function, it is a fatal error, the
 *       function will not return.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_GetConstellationArea
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        le_gnss_Constellation_t satConstellation,
        ///< [IN] GNSS constellation type.
        le_gnss_ConstellationArea_t* constellationAreaPtr
        ///< [OUT] GNSS constellation area.
);

//--------------------------------------------------------------------------------------------------
/**
 * This function enables the use of the 'Extended Ephemeris' file into the GNSS device.
 *
 * @return
 *  - LE_FAULT         The function failed.
 *  - LE_OK            The function succeeded.
 *
 * @warning The settings are platform dependent. Please refer to
 *          @ref platformConstraintsGnss_SettingConfiguration section for full details.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_EnableExtendedEphemerisFile
(
    le_msg_SessionRef_t _ifgen_sessionRef
);

//--------------------------------------------------------------------------------------------------
/**
 * This function disables the use of the 'Extended Ephemeris' file into the GNSS device.
 *
 * @return
 *  - LE_FAULT         The function failed.
 *  - LE_OK            The function succeeded.
 *
 * @warning The settings are platform dependent. Please refer to
 *          @ref platformConstraintsGnss_SettingConfiguration section for full details.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_DisableExtendedEphemerisFile
(
    le_msg_SessionRef_t _ifgen_sessionRef
);

//--------------------------------------------------------------------------------------------------
/**
 * This function must be called to load an 'Extended Ephemeris' file into the GNSS device.
 *
 * @return
 *  - LE_FAULT         The function failed to inject the 'Extended Ephemeris' file.
 *  - LE_TIMEOUT       A time-out occurred.
 *  - LE_FORMAT_ERROR  'Extended Ephemeris' file format error.
 *  - LE_OK            The function succeeded.
 *
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_LoadExtendedEphemerisFile
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        int fd
        ///< [IN] Extended ephemeris file descriptor
);

//--------------------------------------------------------------------------------------------------
/**
 * This function must be called to get the validity of the last injected Extended Ephemeris.
 *
 * @return
 *  - LE_FAULT         The function failed to get the validity
 *  - LE_OK            The function succeeded.
 *
 * @note If the caller is passing an invalid Position sample reference or null pointers into this
 *       function, it is a fatal error, the function will not return.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_GetExtendedEphemerisValidity
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        uint64_t* startTimePtr,
        ///< [OUT] Start time in seconds (since Jan. 1, 1970)
        uint64_t* stopTimePtr
        ///< [OUT] Stop time in seconds (since Jan. 1, 1970)
);

//--------------------------------------------------------------------------------------------------
/**
 * This function must be called to inject the UTC time into the GNSS device.
 *
 * @return
 *  - LE_OK            The function succeeded.
 *  - LE_FAULT         The function failed to inject the UTC time.
 *  - LE_TIMEOUT       A time-out occurred.
 *
 * @note It is mandatory to enable the 'Extended Ephemeris' file injection into the GNSS device with
 * le_gnss_EnableExtendedEphemerisFile() before injecting time with this API.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_InjectUtcTime
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        uint64_t timeUtc,
        ///< [IN] [IN] UTC time since Jan. 1, 1970 in milliseconds
        uint32_t timeUnc
        ///< [IN] [IN] Time uncertainty in milliseconds
);

//--------------------------------------------------------------------------------------------------
/**
 * This function starts the GNSS device.
 *
 * @return
 *  - LE_FAULT         The function failed.
 *  - LE_DUPLICATE     If the GNSS device is already started.
 *  - LE_NOT_PERMITTED If the GNSS device is not initialized or disabled.
 *  - LE_OK            The function succeeded.
 *
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_Start
(
    le_msg_SessionRef_t _ifgen_sessionRef
);

//--------------------------------------------------------------------------------------------------
/**
 * This function starts the GNSS device in the specified start mode.
 *
 * @return
 *  - LE_OK              The function succeeded.
 *  - LE_BAD_PARAMETER   Invalid start mode
 *  - LE_FAULT           The function failed.
 *  - LE_DUPLICATE       If the GNSS device is already started.
 *  - LE_NOT_PERMITTED   If the GNSS device is not initialized or disabled.
 *
 * @warning This function may be subject to limitations depending on the platform. Please refer to
 *          the @ref platformConstraintsGnss page.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_StartMode
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        le_gnss_StartMode_t mode
        ///< [IN] [IN] Start mode
);

//--------------------------------------------------------------------------------------------------
/**
 * This function stops the GNSS device.
 *
 * @return
 *  - LE_FAULT         The function failed.
 *  - LE_DUPLICATE     If the GNSS device is already stopped.
 *  - LE_NOT_PERMITTED If the GNSS device is not initialized or disabled.
 *  - LE_OK            The function succeeded.
 *
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_Stop
(
    le_msg_SessionRef_t _ifgen_sessionRef
);

//--------------------------------------------------------------------------------------------------
/**
 * This function performs a "HOT" restart of the GNSS device.
 *
 * @return
 *  - LE_FAULT         The function failed.
 *  - LE_NOT_PERMITTED If the GNSS device is not enabled or not started.
 *  - LE_OK            The function succeeded.
 *
 * @Note This API can be used to restart the GNSS device. It is equivalent calling le_gnss_Stop()
 *       and le_gnss_Start().
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_ForceHotRestart
(
    le_msg_SessionRef_t _ifgen_sessionRef
);

//--------------------------------------------------------------------------------------------------
/**
 * This function performs a "WARM" restart of the GNSS device.
 *
 * @return
 *  - LE_FAULT         The function failed.
 *  - LE_NOT_PERMITTED If the GNSS device is not enabled or not started.
 *  - LE_OK            The function succeeded.
 *
 * @Note This API has a platform dependent feature. Please refer to
 * @ref platformConstraintsGnss_WarmRestart for further details.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_ForceWarmRestart
(
    le_msg_SessionRef_t _ifgen_sessionRef
);

//--------------------------------------------------------------------------------------------------
/**
 * This function performs a "COLD" restart of the GNSS device.
 *
 * @return
 *  - LE_FAULT         The function failed.
 *  - LE_NOT_PERMITTED If the GNSS device is not enabled or not started.
 *  - LE_OK            The function succeeded.
 *
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_ForceColdRestart
(
    le_msg_SessionRef_t _ifgen_sessionRef
);

//--------------------------------------------------------------------------------------------------
/**
 * This function performs a "FACTORY" restart of the GNSS device.
 *
 * @return
 *  - LE_FAULT         The function failed.
 *  - LE_NOT_PERMITTED If the GNSS device is not enabled or not started.
 *  - LE_OK            The function succeeded.
 *
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_ForceFactoryRestart
(
    le_msg_SessionRef_t _ifgen_sessionRef
);

//--------------------------------------------------------------------------------------------------
/**
 * Get the TTFF in milliseconds
 *
 * @return
 *  - LE_BUSY          The position is not fixed and TTFF can't be measured.
 *  - LE_NOT_PERMITTED If the GNSS device is not enabled or not started.
 *  - LE_OK            Function succeeded.
 *  - LE_FAULT         If there are some other errors.
 *
 * @note If the caller is passing a null pointer into this function, it is a fatal error, the
 *       function will not return.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_GetTtff
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        uint32_t* ttffPtr
        ///< [OUT] TTFF in milliseconds
);

//--------------------------------------------------------------------------------------------------
/**
 * This function enables the GNSS device.
 *
 * @return
 *  - LE_FAULT         The function failed.
 *  - LE_DUPLICATE     If the GNSS device is already enabled.
 *  - LE_NOT_PERMITTED If the GNSS device is not initialized.
 *  - LE_OK            The function succeeded.
 *
 * @warning The settings are platform dependent. Please refer to
 *          @ref platformConstraintsGnss_SettingConfiguration section for full details.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_Enable
(
    le_msg_SessionRef_t _ifgen_sessionRef
);

//--------------------------------------------------------------------------------------------------
/**
 * This function disables the GNSS device.
 *
 * @return
 *  - LE_FAULT         The function failed.
 *  - LE_DUPLICATE     If the GNSS device is already disabled.
 *  - LE_NOT_PERMITTED If the GNSS device is not initialized or started.
 *  - LE_OK            The function succeeded.
 *
 * @warning The settings are platform dependent. Please refer to
 *          @ref platformConstraintsGnss_SettingConfiguration section for full details.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_Disable
(
    le_msg_SessionRef_t _ifgen_sessionRef
);

//--------------------------------------------------------------------------------------------------
/**
 * This function sets the GNSS device acquisition rate.
 *
 * @return
 *  - LE_OK on success
 *  - LE_FAULT on failure
 *  - LE_UNSUPPORTED request not supported
 *  - LE_TIMEOUT a time-out occurred
 *  - LE_NOT_PERMITTED If the GNSS device is not in "ready" state.
 *  - LE_OUT_OF_RANGE  if acquisition rate value is equal to zero
 *
 * @warning This function may be subject to limitations depending on the platform. Please refer to
 *          the @ref platformConstraintsGnss page.
 *
 * @warning The settings are platform dependent. Please refer to
 *          @ref platformConstraintsGnss_SettingConfiguration section for full details.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_SetAcquisitionRate
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        uint32_t rate
        ///< [IN] Acquisition rate in milliseconds.
);

//--------------------------------------------------------------------------------------------------
/**
 * This function gets the GNSS device acquisition rate.
 *
 * @return
 *  - LE_OK on success
 *  - LE_FAULT on failure
 *  - LE_NOT_PERMITTED If the GNSS device is not in "ready" state.
 *
 * @note If the caller is passing a null pointer into this function, it is a fatal error, the
 *       function will not return.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_GetAcquisitionRate
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        uint32_t* ratePtr
        ///< [OUT] Acquisition rate in milliseconds.
);

//--------------------------------------------------------------------------------------------------
/**
 * Add handler function for EVENT 'le_gnss_Position'
 *
 * This event provides information on position.
 *
 *  - A handler reference, which is only needed for later removal of the handler.
 *
 * @note Doesn't return on failure, so there's no need to check the return value for errors.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_gnss_PositionHandlerRef_t ifgen_le_gnss_AddPositionHandler
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        le_gnss_PositionHandlerFunc_t handlerPtr,
        ///< [IN]
        void* contextPtr
        ///< [IN]
);

//--------------------------------------------------------------------------------------------------
/**
 * Remove handler function for EVENT 'le_gnss_Position'
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED void ifgen_le_gnss_RemovePositionHandler
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        le_gnss_PositionHandlerRef_t handlerRef
        ///< [IN]
);

//--------------------------------------------------------------------------------------------------
/**
 * This function gets the position sample's fix state
 *
 *  - LE_OK on success
 *  - LE_FAULT on failure
 *
 * @note If the caller is passing an invalid Position sample reference or a null pointer into this
 *       function, it is a fatal error, the function will not return.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_GetPositionState
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        le_gnss_SampleRef_t positionSampleRef,
        ///< [IN] Position sample's reference.
        le_gnss_FixState_t* statePtr
        ///< [OUT] Position fix state.
);

//--------------------------------------------------------------------------------------------------
/**
 * Get the location's data (Latitude, Longitude, Horizontal accuracy).
 *
 * @return
 *  - LE_FAULT         Function failed to get the location's data
 *  - LE_OUT_OF_RANGE  At least one of the retrieved parameters is invalid (set to INT32_MAX).
 *  - LE_OK            Function succeeded.
 *
 * @note latitudePtr, longitudePtr and hAccuracyPtr can be set to NULL if not needed.
 *
 * @note The latitude and longitude values are based on the WGS84 standard coordinate system.
 *
 * @note The latitude and longitude values are given in degrees with 6 decimal places like:
 *       Latitude +48858300 = 48.858300 degrees North
 *       Longitude +2294400 = 2.294400 degrees East
 *       (The latitude and longitude values are given in degrees, minutes, seconds in NMEA frame)
 *
 * @note In case the function returns LE_OUT_OF_RANGE, some of the retrieved parameters may be
 *       valid. Please compare them with INT32_MAX.
 *
 * @note If the caller is passing an invalid Position sample reference into this function,
 *       it is a fatal error, the function will not return.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_GetLocation
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        le_gnss_SampleRef_t positionSampleRef,
        ///< [IN] Position sample's reference.
        int32_t* latitudePtr,
        ///< [OUT] WGS84 Latitude in degrees, positive North [resolution 1e-6].
        int32_t* longitudePtr,
        ///< [OUT] WGS84 Longitude in degrees, positive East [resolution 1e-6].
        int32_t* hAccuracyPtr
        ///< [OUT] Horizontal position's accuracy in meters [resolution 1e-2].
);

//--------------------------------------------------------------------------------------------------
/**
 * Get the position sample's altitude.
 *
 * @return
 *  - LE_FAULT         Function failed to get the altitude. Invalid Position reference provided.
 *  - LE_OUT_OF_RANGE  At least one of the retrieved parameters is invalid (set to INT32_MAX).
 *  - LE_OK            Function succeeded.
 *
 * @note Altitude is in meters, above Mean Sea Level, with 3 decimal places (3047 = 3.047 meters).
 *
 * @note For a 2D position fix, the altitude will be indicated as invalid and set to INT32_MAX
 *
 * @note Vertical position accuracy is default set to meters with 1 decimal place (3047 = 3.0
 *       meters). To change its accuracy, call the @c le_gnss_SetDataResolution() function. Vertical
 *       position accuracy is set as data type and accuracy from 0 to 3 decimal place is set as
 *       resolution.
 *
 * @note In case the function returns LE_OUT_OF_RANGE, some of the retrieved parameters may be
 *       valid. Please compare them with INT32_MAX.
 *
 * @note If the caller is passing an invalid Position reference into this function,
 *       it is a fatal error, the function will not return.
 *
 * @note altitudePtr, altitudeAccuracyPtr can be set to NULL if not needed.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_GetAltitude
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        le_gnss_SampleRef_t positionSampleRef,
        ///< [IN] Position sample's reference.
        int32_t* altitudePtr,
        ///< [OUT] Altitude in meters, above Mean Sea Level [resolution 1e-3].
        int32_t* vAccuracyPtr
        ///< [OUT] Vertical position's accuracy in meters.
);

//--------------------------------------------------------------------------------------------------
/**
 * Get the position sample's time.
 *
 * @return
 *  - LE_FAULT         Function failed to get the time.
 *  - LE_OUT_OF_RANGE  The retrieved time is invalid (all fields are set to 0).
 *  - LE_OK            Function succeeded.
 *
 * @note If the caller is passing an invalid Position sample reference or null pointers into this
 *       function, it is a fatal error, the function will not return.
 *
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_GetTime
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        le_gnss_SampleRef_t positionSampleRef,
        ///< [IN] Position sample's reference.
        uint16_t* hoursPtr,
        ///< [OUT] UTC Hours into the day [range 0..23].
        uint16_t* minutesPtr,
        ///< [OUT] UTC Minutes into the hour [range 0..59].
        uint16_t* secondsPtr,
        ///< [OUT] UTC Seconds into the minute [range 0..59].
        uint16_t* millisecondsPtr
        ///< [OUT] UTC Milliseconds into the second [range 0..999].
);

//--------------------------------------------------------------------------------------------------
/**
 * Get the position sample's GPS time.
 *
 * @return
 *  - LE_FAULT         Function failed to get the time.
 *  - LE_OUT_OF_RANGE  The retrieved time is invalid (all fields are set to 0).
 *  - LE_OK            Function succeeded.
 *
 * @note If the caller is passing an invalid Position sample reference or null pointers into this
 *       function, it is a fatal error, the function will not return.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_GetGpsTime
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        le_gnss_SampleRef_t positionSampleRef,
        ///< [IN] Position sample's reference.
        uint32_t* gpsWeekPtr,
        ///< [OUT] GPS week number from midnight, Jan. 6, 1980.
        uint32_t* gpsTimeOfWeekPtr
        ///< [OUT] Amount of time in milliseconds into the GPS week.
);

//--------------------------------------------------------------------------------------------------
/**
 *  Get the position sample's epoch time.
 *
 * @return
 *  - LE_FAULT         Function failed to acquire the epoch time.
 *  - LE_OK            Function succeeded.
 *  - LE_OUT_OF_RANGE  The retrieved time is invalid (all fields are set to 0).
 *
 * @note The epoch time is the number of seconds elapsed since January 1, 1970
 *       (midnight UTC/GMT), not counting leaps seconds.
 *
 * @note If the caller is passing an invalid position sample reference or a null pointer into this
 *       function, it is a fatal error, the function will not return.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_GetEpochTime
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        le_gnss_SampleRef_t positionSampleRef,
        ///< [IN] Position sample's reference.
        uint64_t* millisecondsPtr
        ///< [OUT] Milliseconds since Jan. 1, 1970.
);

//--------------------------------------------------------------------------------------------------
/**
 * Get the position sample's time accurary.
 *
 * @return
 *  - LE_FAULT         Function failed to get the time.
 *  - LE_OUT_OF_RANGE  The retrieved time accuracy is invalid (set to UINT16_MAX).
 *  - LE_OK            Function succeeded.
 *
 * @note If the caller is passing an invalid position sample reference or a null pointer into this
 *       function, it is a fatal error, the function will not return.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_GetTimeAccuracy
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        le_gnss_SampleRef_t positionSampleRef,
        ///< [IN] Position sample's reference.
        uint32_t* timeAccuracyPtr
        ///< [OUT] Estimated time accuracy in nanoseconds
);

//--------------------------------------------------------------------------------------------------
/**
 * Get the position sample's UTC leap seconds in advance
 *
 * @return
 *  - LE_FAULT         Function failed to get the leap seconds.
 *  - LE_OUT_OF_RANGE  The retrieved time accuracy is invalid (set to UINT8_MAX).
 *  - LE_OK            Function succeeded.
 *
 * @note The leap seconds in advance is the accumulated time in seconds since the start of GPS Epoch
 * time (Jan 6, 1980). This value has to be added to the UTC time (since Jan. 1, 1970)
 *
 * @note Insertion of each UTC leap second is usually decided about six months in advance by the
 * International Earth Rotation and Reference Systems Service (IERS).
 *
 * @note If the caller is passing an invalid position sample reference or a null pointer into this
 *       function, it is a fatal error, the function will not return.
 *
 * @deprecated This function is deprecated, le_gnss_GetLeapSeconds should be used instead.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_GetGpsLeapSeconds
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        le_gnss_SampleRef_t positionSampleRef,
        ///< [IN] Position sample's reference.
        uint8_t* leapSecondsPtr
        ///< [OUT] UTC leap seconds in advance in seconds
);

//--------------------------------------------------------------------------------------------------
/**
 * Get leap seconds information.
 *
 * @return
 *  - LE_OK            Function succeeded.
 *  - LE_FAULT         Function failed to get the data.
 *  - LE_TIMEOUT       Timeout occured.
 *  - LE_UNSUPPORTED   Not supported on this platform.
 *
 * @note Insertion of each UTC leap second is usually decided about six months in advance by the
 * International Earth Rotation and Reference Systems Service (IERS).
 *
 * @note If the caller is passing a null pointer into this function, it is considered a fatal
 * error and the function will not return.
 *
 * @note If the return value of a parameter is INT32_MAX/UINT64_MAX, the parameter is not valid.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_GetLeapSeconds
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        uint64_t* gpsTimePtr,
        ///< [OUT] The number of milliseconds of GPS time since midnight,
        ///< Jan. 6, 1980.
        int32_t* currentLeapSecondsPtr,
        ///< [OUT] Current UTC leap seconds value in milliseconds.
        uint64_t* changeEventTimePtr,
        ///< [OUT] The number of milliseconds since midnight, Jan. 6, 1980
        ///< to the next leap seconds change event.
        int32_t* nextLeapSecondsPtr
        ///< [OUT] UTC leap seconds value to be applied at the change
        ///< event time in milliseconds.
);

//--------------------------------------------------------------------------------------------------
/**
 * Get the position sample's date.
 *
 * @return
 *  - LE_FAULT         Function failed to get the date.
 *  - LE_OUT_OF_RANGE  The retrieved date is invalid (all fields are set to 0).
 *  - LE_OK            Function succeeded.
 *
 * @note If the caller is passing an invalid Position sample reference or null pointers into this
 *       function, it is a fatal error, the function will not return.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_GetDate
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        le_gnss_SampleRef_t positionSampleRef,
        ///< [IN] Position sample's reference.
        uint16_t* yearPtr,
        ///< [OUT] UTC Year A.D. [e.g. 2014].
        uint16_t* monthPtr,
        ///< [OUT] UTC Month into the year [range 1...12].
        uint16_t* dayPtr
        ///< [OUT] UTC Days into the month [range 1...31].
);

//--------------------------------------------------------------------------------------------------
/**
 * Get the position sample's horizontal speed.
 *
 *  - LE_FAULT         Function failed to find the positionSample.
 *  - LE_OUT_OF_RANGE  At least one of the retrieved parameters is invalid (set to UINT32_MAX).
 *  - LE_OK            Function succeeded.
 *
 * @note hSpeedPtr, hSpeedAccuracyPtr can be set to NULL if not needed.
 *
 * @note Horizontal speed is in meters/second with 2 decimal places (3047 = 30.47 meters/second).
 *
 * @note Horizontal speed accuracy estimate is default set to meters/second with 1 decimal place
 *       (304 = 30.4 meters/second). To change its accuracy, call the @c le_gnss_SetDataResolution()
 *       function. Horizontal speed accuracy estimate is set as data type and accuracy from 0 to 3
 *       decimal place is set as resolution.
 *
 * @note In case the function returns LE_OUT_OF_RANGE, some of the retrieved parameters may be
 *       valid. Please compare them with UINT32_MAX.
 *
 * @note If the caller is passing an invalid Position sample reference into this function,
 *       it is a fatal error, the function will not return.
 *
 * @warning The Horizontal speed accuracy is platform dependent. Please refer to
 *          @ref platformConstraintsGnss_speedAccuracies section for full details.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_GetHorizontalSpeed
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        le_gnss_SampleRef_t positionSampleRef,
        ///< [IN] Position sample's reference.
        uint32_t* hspeedPtr,
        ///< [OUT] Horizontal speed in meters/second [resolution 1e-2].
        uint32_t* hspeedAccuracyPtr
        ///< [OUT] Horizontal speed's accuracy estimate in meters/second.
);

//--------------------------------------------------------------------------------------------------
/**
 * Get the position sample's vertical speed.
 *
 * @return
 *  - LE_FAULT         The function failed to find the positionSample.
 *  - LE_OUT_OF_RANGE  At least one of the retrieved parameters is not valid (set to INT32_MAX).
 *  - LE_OK            The function succeeded.
 *
 * @note vSpeedPtr, vSpeedAccuracyPtr can be set to NULL if not needed.
 *
 * @note For a 2D position Fix, the vertical speed will be indicated as invalid
 * and set to INT32_MAX.
 *
 * @note Vertical speed accuracy estimate is default set to meters/second with 1 decimal place
 *       (304 = 30.4 meters/second). To change its accuracy, call the @c le_gnss_SetDataResolution()
 *       function. Vertical speed accuracy estimate is set as data type and accuracy from 0 to 3
 *       decimal place is set as resolution.
 *
 * @note In case the function returns LE_OUT_OF_RANGE, some of the retrieved parameters may be
 *       valid. Please compare them with INT32_MAX.
 *
 * @note If the caller is passing an invalid Position sample reference into this function,
 *       it is a fatal error, the function will not return.
 *
 * @warning The Vertical speed accuracy is platform dependent. Please refer to
 *          @ref platformConstraintsGnss_speedAccuracies section for full details.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_GetVerticalSpeed
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        le_gnss_SampleRef_t positionSampleRef,
        ///< [IN] Position sample's reference.
        int32_t* vspeedPtr,
        ///< [OUT] Vertical speed in meters/second [resolution 1e-2],
        ///< positive up.
        int32_t* vspeedAccuracyPtr
        ///< [OUT] Vertical speed's accuracy estimate in meters/second.
);

//--------------------------------------------------------------------------------------------------
/**
 * Get the position sample's direction. Direction of movement is the direction that the vehicle or
 * person is actually moving.
 *
 * @return
 *  - LE_FAULT         Function failed to find the positionSample.
 *  - LE_OUT_OF_RANGE  At least one of the retrieved parameters is invalid (set to UINT32_MAX).
 *  - LE_OK            Function succeeded.
 *
 * @note Direction and direction accuracy are given in degrees with 1 decimal place: 1755 = 175.5
 *       degrees.
 *       Direction ranges from 0 to 359.9 degrees, where 0 is True North.
 *
 * @note In case the function returns LE_OUT_OF_RANGE, some of the retrieved parameters may be
 *       valid. Please compare them with UINT32_MAX.
 *
 * @note directionPtr, directionAccuracyPtr can be set to NULL if not needed.
 *
 * @note If the caller is passing an invalid Position sample reference into this function,
 *       it is a fatal error, the function will not return.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_GetDirection
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        le_gnss_SampleRef_t positionSampleRef,
        ///< [IN] Position sample's reference.
        uint32_t* directionPtr,
        ///< [OUT] Direction in degrees [resolution 1e-1].
        ///< Range: 0 to 359.9, where 0 is True North
        uint32_t* directionAccuracyPtr
        ///< [OUT] Direction's accuracy estimate
        ///< in degrees [resolution 1e-1].
);

//--------------------------------------------------------------------------------------------------
/**
 * Get the Satellites Vehicle information.
 *
 * @return
 *  - LE_FAULT         Function failed to find the positionSample.
 *  - LE_OUT_OF_RANGE  At least one of the retrieved parameters is invalid.
 *  - LE_OK            Function succeeded.
 *
 * @note satId[] can be set to 0 if that information list index is not configured, so
 * all satellite parameters (satConst[], satSnr[],satAzim[], satElev[]) are fixed to 0.
 *
 * @note For LE_OUT_OF_RANGE returned code, invalid value depends on field type:
 * UINT16_MAX for satId, LE_GNSS_SV_CONSTELLATION_UNDEFINED for satConst, false for satUsed,
 * UINT8_MAX for satSnr, UINT16_MAX for satAzim, UINT8_MAX for satElev.
 *
 * @note In case the function returns LE_OUT_OF_RANGE, some of the retrieved parameters may be
 *       valid.
 *
 * @note If the caller is passing an invalid Position sample reference into this function,
 *       it is a fatal error, the function will not return.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_GetSatellitesInfo
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        le_gnss_SampleRef_t positionSampleRef,
        ///< [IN] Position sample's reference.
        uint16_t* satIdPtr,
        ///< [OUT] Satellites in View ID number, referring
        ///< to NMEA standard.
        size_t* satIdSizePtr,
        ///< [INOUT]
        le_gnss_Constellation_t* satConstPtr,
        ///< [OUT] GNSS constellation type.
        size_t* satConstSizePtr,
        ///< [INOUT]
        bool* satUsedPtr,
        ///< [OUT] TRUE if satellite in View Used
        ///< for Navigation.
        size_t* satUsedSizePtr,
        ///< [INOUT]
        uint8_t* satSnrPtr,
        ///< [OUT] Satellites in View Signal To
        ///< Noise Ratio (C/No) [dBHz].
        size_t* satSnrSizePtr,
        ///< [INOUT]
        uint16_t* satAzimPtr,
        ///< [OUT] Satellites in View Azimuth [degrees].
        ///< Range: 0 to 360
        ///< If Azimuth angle is currently unknown,
        ///< the value is set to UINT16_MAX.
        size_t* satAzimSizePtr,
        ///< [INOUT]
        uint8_t* satElevPtr,
        ///< [OUT] Satellites in View Elevation [degrees].
        ///< Range: 0 to 90
        ///< If Elevation angle is currently unknown,
        ///< the value is set to UINT8_MAX.
        size_t* satElevSizePtr
        ///< [INOUT]
);

//--------------------------------------------------------------------------------------------------
/**
 * Get the SBAS constellation category given the SBAS satellite number ID.
 *
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_gnss_SbasConstellationCategory_t ifgen_le_gnss_GetSbasConstellationCategory
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        uint16_t satId
        ///< [IN] SBAS satellite number ID, referring to NMEA standard.
);

//--------------------------------------------------------------------------------------------------
/**
 * Get the Satellites Vehicle status.
 *
 * @return
 *  - LE_FAULT         Function failed to find the positionSample.
 *  - LE_OUT_OF_RANGE  At least one of the retrieved parameters is invalid (set to UINT8_MAX).
 *  - LE_OK            Function succeeded.
 *
 * @note In case the function returns LE_OUT_OF_RANGE, some of the retrieved parameters may be
 *       valid. Please compare them with UINT8_MAX.
 *
 * @note If the caller is passing an invalid Position sample reference into this function,
 *       it is a fatal error, the function will not return.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_GetSatellitesStatus
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        le_gnss_SampleRef_t positionSampleRef,
        ///< [IN] Position sample's reference.
        uint8_t* satsInViewCountPtr,
        ///< [OUT] Number of satellites expected to be in view.
        uint8_t* satsTrackingCountPtr,
        ///< [OUT] Number of satellites in view, when tracking.
        uint8_t* satsUsedCountPtr
        ///< [OUT] Number of satellites in view used for Navigation.
);

//--------------------------------------------------------------------------------------------------
/**
 * Get the DOP parameters (Dilution Of Precision) for the fixed position
 *
 * @return
 *  - LE_FAULT         Function failed to find the positionSample.
 *  - LE_OUT_OF_RANGE  At least one of the retrieved parameters is invalid (set to UINT16_MAX).
 *  - LE_OK            Function succeeded.
 *
 * @deprecated This function is deprecated, le_gnss_GetDilutionOfPrecision() should be used for
 *             new code.
 *
 * @note The DOP values are given with 3 decimal places like: DOP value 2200 = 2.200
 *
 * @note In case the function returns LE_OUT_OF_RANGE, some of the retrieved parameters may be
 *       valid. Please compare them with UINT16_MAX.
 *
 * @note If the caller is passing an invalid Position sample reference into this function,
 *       it is a fatal error, the function will not return.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_GetDop
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        le_gnss_SampleRef_t positionSampleRef,
        ///< [IN] Position sample's reference.
        uint16_t* hdopPtr,
        ///< [OUT] Horizontal Dilution of Precision [resolution 1e-3].
        uint16_t* vdopPtr,
        ///< [OUT] Vertical Dilution of Precision [resolution 1e-3].
        uint16_t* pdopPtr
        ///< [OUT] Position Dilution of Precision [resolution 1e-3].
);

//--------------------------------------------------------------------------------------------------
/**
 * Get the DOP parameter (Dilution Of Precision) for the fixed position.
 *
 * @return
 *  - LE_FAULT         Function failed to find the DOP value.
 *  - LE_OUT_OF_RANGE  The retrieved parameter is invalid (set to UINT16_MAX).
 *  - LE_OK            Function succeeded.
 *
 * @note This function replaces the deprecated function le_gnss_GetDop().
 *
 * @note The DOP value is given with 3 decimal places by default like: DOP value 2200 = 2.200
 *       The resolution can be modified by calling the @c le_gnss_SetDopResolution() function.
 *
 * @note If the caller is passing an invalid Position sample reference into this function,
 *       it is a fatal error, the function will not return.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_GetDilutionOfPrecision
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        le_gnss_SampleRef_t positionSampleRef,
        ///< [IN] Position sample's reference.
        le_gnss_DopType_t dopType,
        ///< [IN] Dilution of Precision type.
        uint16_t* dopPtr
        ///< [OUT] Dilution of Precision corresponding to the dopType
);

//--------------------------------------------------------------------------------------------------
/**
 * Get the position sample's altitude with respect to the WGS-84 ellipsoid
 *
 * @return
 *  - LE_FAULT         Function failed to get the altitude.
 *  - LE_OUT_OF_RANGE  The altitudeOnWgs84 is invalid (set to INT32_MAX).
 *  - LE_OK            Function succeeded.
 *
 * @note altitudeOnWgs84 is in meters, with respect to the WGS-84 ellipsoid with 3 decimal
 *       places (3047 = 3.047 meters).
 *
 * @note For a 2D position fix, the altitude with respect to the WGS-84 ellipsoid will be indicated
 *       as invalid and set to INT32_MAX.
 *
 * @note If the caller is passing an invalid Position reference or a null pointer into this
 *       function, it is a fatal error, the function will not return.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_GetAltitudeOnWgs84
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        le_gnss_SampleRef_t positionSampleRef,
        ///< [IN] Position sample's reference.
        int32_t* altitudeOnWgs84Ptr
        ///< [OUT] Altitude in meters, between WGS-84 earth ellipsoid
        ///< and mean sea level [resolution 1e-3].
);

//--------------------------------------------------------------------------------------------------
/**
 * Get the position sample's magnetic deviation. It is the difference between the bearing to
 * true north and the bearing shown on a magnetic compass. The deviation is positive when the
 * magnetic north is east of true north.
 *
 * @return
 *  - LE_FAULT         Function failed to find the positionSample.
 *  - LE_OUT_OF_RANGE  The magneticDeviation is invalid (set to INT32_MAX).
 *  - LE_OK            Function succeeded.
 *
 * @note magneticDeviation is in degrees, with 1 decimal places (47 = 4.7 degree).
 *
 * @note If the caller is passing an invalid Position sample reference into this function,
 *       it is a fatal error, the function will not return.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_GetMagneticDeviation
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        le_gnss_SampleRef_t positionSampleRef,
        ///< [IN] Position sample's reference.
        int32_t* magneticDeviationPtr
        ///< [OUT] MagneticDeviation in degrees [resolution 1e-1].
);

//--------------------------------------------------------------------------------------------------
/**
 * This function gets the last updated position sample object reference.
 *
 * @return A reference to last Position's sample.
 *
 * @note
 *      On failure, the process exits, so you don't have to worry about checking the returned
 *      reference for validity.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_gnss_SampleRef_t ifgen_le_gnss_GetLastSampleRef
(
    le_msg_SessionRef_t _ifgen_sessionRef
);

//--------------------------------------------------------------------------------------------------
/**
 * This function must be called to release the position sample.
 *
 * @note If the caller is passing an invalid Position sample reference into this function,
 *       it is a fatal error, the function will not return.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED void ifgen_le_gnss_ReleaseSampleRef
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        le_gnss_SampleRef_t positionSampleRef
        ///< [IN] Position sample's reference.
);

//--------------------------------------------------------------------------------------------------
/**
 * This function sets the SUPL Assisted-GNSS mode.
 *
 * @return
 *  - LE_OK on success
 *  - LE_FAULT on failure
 *  - LE_UNSUPPORTED request not supported
 *  - LE_TIMEOUT a time-out occurred
 *
 * @warning The settings are platform dependent. Please refer to
 *          @ref platformConstraintsGnss_SettingConfiguration section for full details.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_SetSuplAssistedMode
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        le_gnss_AssistedMode_t assistedMode
        ///< [IN] Assisted-GNSS mode.
);

//--------------------------------------------------------------------------------------------------
/**
 * This function gets the SUPL Assisted-GNSS mode.
 *
 * @return
 *  - LE_OK on success
 *  - LE_FAULT on failure
 *
 * @note If the caller is passing a null pointer into this function, it is a fatal error, the
 *       function will not return.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_GetSuplAssistedMode
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        le_gnss_AssistedMode_t* assistedModePtr
        ///< [OUT] Assisted-GNSS mode.
);

//--------------------------------------------------------------------------------------------------
/**
 * This function sets the SUPL server URL.
 * That server URL is a NULL-terminated string with a maximum string length (including NULL
 * terminator) equal to 256. Optionally the port number is specified after a colon.
 *
 * @return
 *  - LE_OK on success
 *  - LE_FAULT on failure
 *  - LE_BUSY service is busy
 *  - LE_TIMEOUT a time-out occurred
 *
 * @note If the SUPL server URL size is bigger than the maximum string length (including NULL
 * terminator) size, it is a fatal error, the function will not return.
 *
 * @warning The settings are platform dependent. Please refer to
 *          @ref platformConstraintsGnss_SettingConfiguration section for full details.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_SetSuplServerUrl
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        const char* LE_NONNULL suplServerUrl
        ///< [IN] SUPL server URL.
);

//--------------------------------------------------------------------------------------------------
/**
 * This function injects the SUPL certificate to be used in A-GNSS sessions. Certificates must
 * be encoded in DER. Other certificate encryptions (e.g., PEM, CER and CRT)
 * aren't supported.
 *
 * @return
 *  - LE_OK on success
 *  - LE_BAD_PARAMETER on invalid parameter
 *  - LE_FAULT on failure
 *  - LE_BUSY service is busy
 *  - LE_TIMEOUT a time-out occurred
 *
 * @note If the SUPL certificate size is bigger than the Maximum SUPL certificate size,
 * it is a fatal error, the function will not return.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_InjectSuplCertificate
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        uint8_t suplCertificateId,
        ///< [IN] ID of the SUPL certificate.
        ///< Certificate ID range is 0 to 9
        uint16_t suplCertificateLen,
        ///< [IN] SUPL certificate size in Bytes.
        const char* LE_NONNULL suplCertificate
        ///< [IN] SUPL certificate contents.
);

//--------------------------------------------------------------------------------------------------
/**
 * This function deletes the SUPL certificate.
 *
 * @return
 *  - LE_OK on success
 *  - LE_BAD_PARAMETER on invalid parameter
 *  - LE_FAULT on failure
 *  - LE_BUSY service is busy
 *  - LE_TIMEOUT a time-out occurred
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_DeleteSuplCertificate
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        uint8_t suplCertificateId
        ///< [IN] ID of the SUPL certificate.
        ///< Certificate ID range is 0 to 9
);

//--------------------------------------------------------------------------------------------------
/**
 * This function sets the enabled NMEA sentences using a bit mask.
 *
 * @return
 *  - LE_OK             Success
 *  - LE_BAD_PARAMETER  Bit mask exceeds the maximal value
 *  - LE_FAULT          Failure
 *  - LE_BUSY           Service is busy
 *  - LE_TIMEOUT        Timeout occurred
 *  - LE_NOT_PERMITTED  GNSS device is not in "ready" state
 *
 * @warning This function may be subject to limitations depending on the platform. Please refer to
 *          the @ref platformConstraintsGnss page.
 *
 * @note Some NMEA sentences are unsupported depending on the platform. Please refer to
 *       @ref platformConstraintsGnss_nmeaMask section for full details. Setting an unsuported NMEA
 *       sentence won't report an error.
 *
 * @warning The settings are platform dependent. Please refer to
 *          @ref platformConstraintsGnss_SettingConfiguration section for full details.
 *
 * @deprecated LE_GNSS_NMEA_MASK_PQXFI is deprecated. LE_GNSS_NMEA_MASK_PTYPE should be used
 *             instead. Setting LE_GNSS_NMEA_MASK_PTYPE will also set LE_GNSS_NMEA_MASK_PQXFI.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_SetNmeaSentences
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        le_gnss_NmeaBitMask_t nmeaMask
        ///< [IN] Bit mask for enabled NMEA sentences.
);

//--------------------------------------------------------------------------------------------------
/**
 * This function gets the bit mask for the enabled NMEA sentences.
 *
 * @return
 *  - LE_OK             Success
 *  - LE_FAULT          Failure
 *  - LE_BUSY           Service is busy
 *  - LE_TIMEOUT        Timeout occurred
 *  - LE_NOT_PERMITTED  GNSS device is not in "ready" state
 *
 * @note If the caller is passing a null pointer to this function, it is a fatal error, the
 *       function will not return.
 *
 * @note Some NMEA sentences are unsupported depending on the platform. Please refer to
 *       @ref platformConstraintsGnss_nmeaMask section for full details. The bit mask for an unset
 *       or unsupported NMEA sentence is zero.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_GetNmeaSentences
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        le_gnss_NmeaBitMask_t* nmeaMaskPtrPtr
        ///< [OUT] Bit mask for enabled NMEA sentences.
);

//--------------------------------------------------------------------------------------------------
/**
 * This function returns the status of the GNSS device.
 *
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_gnss_State_t ifgen_le_gnss_GetState
(
    le_msg_SessionRef_t _ifgen_sessionRef
);

//--------------------------------------------------------------------------------------------------
/**
 * This function sets the GNSS minimum elevation.
 *
 * @return
 *  - LE_OK on success
 *  - LE_FAULT on failure
 *  - LE_OUT_OF_RANGE if the minimum elevation is above range
 *  - LE_UNSUPPORTED request not supported
 *
 * @warning The settings are platform dependent. Please refer to
 *          @ref platformConstraintsGnss_SettingConfiguration section for full details.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_SetMinElevation
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        uint8_t minElevation
        ///< [IN] Minimum elevation in degrees [range 0..90].
);

//--------------------------------------------------------------------------------------------------
/**
 * This function gets the GNSS minimum elevation.
 *
 * @return
 *  - LE_OK on success
 *  - LE_FAULT on failure
 *  - LE_UNSUPPORTED request not supported
 *
 * @note If the caller is passing n null pointer to this function, it is a fatal error, the
 *       function will not return.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_GetMinElevation
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        uint8_t* minElevationPtrPtr
        ///< [OUT] Minimum elevation in degrees [range 0..90].
);

//--------------------------------------------------------------------------------------------------
/**
 * Set the resolution for the DOP parameters
 *
 * @return LE_OK               Function succeeded.
 * @return LE_BAD_PARAMETER    Invalid parameter provided.
 * @return LE_FAULT            Function failed.
 *
 * @note The function sets the same resolution to all DOP values returned by
 *       le_gnss_GetDilutionOfPrecision() API. The resolution setting takes effect immediately.
 *
 * @note The resolution setting is done per client session.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_SetDopResolution
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        le_gnss_Resolution_t resolution
        ///< [IN] Resolution.
);

//--------------------------------------------------------------------------------------------------
/**
 * Set the resolution for the specific type of data
 *
 * @return LE_OK               Function succeeded.
 * @return LE_BAD_PARAMETER    Invalid parameter provided.
 * @return LE_FAULT            Function failed.
 *
 * @note The resolution setting takes effect immediately and is not persistent to reset.
 *
 * @note The resolution setting is done per client session.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_SetDataResolution
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        le_gnss_DataType_t dataType,
        ///< [IN] Data type.
        le_gnss_Resolution_t resolution
        ///< [IN] Resolution.
);

//--------------------------------------------------------------------------------------------------
/**
 * This function converts a location data parameter from/to multi-coordinate system
 *
 * @return
 *  - LE_OK on success
 *  - LE_FAULT on failure
 *  - LE_BAD_PARAMETER Invalid parameter provided.
 *  - LE_UNSUPPORTED request not supported
 *
 * @note The resolution of location data parameter remains unchanged after the conversion.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_ConvertDataCoordinateSystem
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        le_gnss_CoordinateSystem_t coordinateSrc,
        ///< [IN] Coordinate system to convert from.
        le_gnss_CoordinateSystem_t coordinateDst,
        ///< [IN] Coordinate system to convert to.
        le_gnss_LocationDataType_t locationDataType,
        ///< [IN] Type of location data to convert.
        int64_t locationDataSrc,
        ///< [IN] Data to convert.
        int64_t* locationDataDstPtr
        ///< [OUT] Converted Data.
);

//--------------------------------------------------------------------------------------------------
/**
 * Enables the EXT_GPS_LNA_EN signal
 *
 * @return LE_OK               Function succeeded.
 * @return LE_NOT_PERMITTED    GNSS is not in the ready state
 * @return LE_UNSUPPORTED      Function not supported on this platform
 *
 * @note The EXT_GPS_LNA_EN signal will be set high when the GNSS state is active
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_EnableExternalLna
(
    le_msg_SessionRef_t _ifgen_sessionRef
);

//--------------------------------------------------------------------------------------------------
/**
 * Disables the EXT_GPS_LNA_EN signal
 *
 * @return LE_OK               Function succeeded.
 * @return LE_NOT_PERMITTED    GNSS is not in the ready state
 * @return LE_UNSUPPORTED      Function not supported on this platform
 *
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_DisableExternalLna
(
    le_msg_SessionRef_t _ifgen_sessionRef
);

//--------------------------------------------------------------------------------------------------
/**
 * Returns a bitmask containing all NMEA sentences supported on this platform
 *
 * @return LE_OK               Function succeeded.
 * @return LE_UNSUPPORTED      Function not supported on this platform.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_GetSupportedNmeaSentences
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        le_gnss_NmeaBitMask_t* NmeaMaskPtr
        ///< [OUT] Supported NMEA sentences
);

//--------------------------------------------------------------------------------------------------
/**
 * Returns a bitmask containing all satellite constellations supported on this platform
 *
 * @return LE_OK               Function succeeded.
 * @return LE_UNSUPPORTED      Function not supported on this platform.
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_GetSupportedConstellations
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        le_gnss_ConstellationBitMask_t* constellationMaskPtr
        ///< [OUT] Supported GNSS constellations
);

//--------------------------------------------------------------------------------------------------
/**
 * Get the minimum NMEA rate supported on this platform
 *
 * @return LE_OK               Function succeeded.
 * @return LE_UNSUPPORTED      Function not supported on this platform
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_GetMinNmeaRate
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        uint32_t* minNmeaRatePtr
        ///< [OUT] Minimum NMEA rate in milliseconds.
);

//--------------------------------------------------------------------------------------------------
/**
 * Get the maximum NMEA rate supported on this platform
 *
 * @return LE_OK               Function succeeded.
 * @return LE_UNSUPPORTED      Function not supported on this platform
 */
//--------------------------------------------------------------------------------------------------
LE_SHARED le_result_t ifgen_le_gnss_GetMaxNmeaRate
(
    le_msg_SessionRef_t _ifgen_sessionRef,
        uint32_t* maxNmeaRatePtr
        ///< [OUT] Maximum NMEA rate in milliseconds.
);

#endif // LE_GNSS_COMMON_H_INCLUDE_GUARD
