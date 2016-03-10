/**********************************************************
 *            AUTOGENERATED FILE                          *
 *             DO NOT MODIFY IT                           *
 *                                                        *
 * To add new commands :                                  *
 *  - Modify ../Xml/commands.xml file                     *
 *  - Re-run generateFeatureControllers.py script         *
 *                                                        *
 **********************************************************/

/**
* @file ARCONTROLLER_JNI_Device
* @brief ARDeviceController JNI device c file.
*/

/*****************************************
 *
 *             include file :
 *
 *****************************************/

#include <jni.h>
#include <stdlib.h>

#include <libARSAL/ARSAL_Print.h>

#include <libARDiscovery/ARDISCOVERY_Device.h>

#include <libARController/ARCONTROLLER_Error.h>
#include <libARController/ARCONTROLLER_Stream.h>
#include <libARController/ARCONTROLLER_Device.h>

/*****************************************
 *
 *             define :
 *
 *****************************************/

#define ARCONTROLLER_JNIDEVICE_TAG "JNIControllerDevice"

/**
 * @brief 
 */
typedef struct
{
    ARCONTROLLER_Device_t *nativeDeviceController; /**< native Device Controller*/
    jobject jDeviceController; /**< java DeviceController*/
}ARCONTROLLER_JNIDeviceController_t;

static JavaVM *ARCONTROLLER_JNIDEVICE_VM; /**< reference to the java virtual machine */

static jmethodID ARCONTROLLER_JNIDEVICE_METHOD_ON_STATE_CHANGED;
static jmethodID ARCONTROLLER_JNIDEVICE_METHOD_ON_EXTENSION_STATE_CHANGED;
static jmethodID ARCONTROLLER_JNIDEVICE_METHOD_ON_COMMAND_RECEIVED;
static jmethodID ARCONTROLLER_JNIDEVICE_METHOD_DECODER_CONFIG_CALLBACK;
static jmethodID ARCONTROLLER_JNIDEVICE_METHOD_DID_RECEIVE_FRAME_CALLBACK;
static jmethodID ARCONTROLLER_JNIDEVICE_METHOD_TIMEOUT_FRAME_CALLBACK;

static jclass jARControllerCodecH264Cls;
static jmethodID ARCONTROLLER_JNIDEVICE_METHOD_NEW_CODEC_H264;

static jclass jARControllerCodecMJPEGCls;
static jmethodID ARCONTROLLER_JNIDEVICE_METHOD_NEW_CODEC_MJPEG;

/*****************************************
 *
 *             private header:
 *
 *****************************************/
ARCONTROLLER_JNIDeviceController_t *ARCONTROLLER_JNI_Device_NewJNIDeviceController (JNIEnv *env, jobject thizz, ARDISCOVERY_Device_t *discoveryDevice, eARCONTROLLER_ERROR *error);
void ARCONTROLLER_JNI_Device_DeleteJNIDeviceController (JNIEnv *env, ARCONTROLLER_JNIDeviceController_t **jniDeviceController);

void ARCONTROLLER_JNI_Device_StateChanged (eARCONTROLLER_DEVICE_STATE newState, eARCONTROLLER_ERROR error, void *customData);
void ARCONTROLLER_JNI_Device_ExtensionStateChanged (eARCONTROLLER_DEVICE_STATE newState, eARDISCOVERY_PRODUCT product, const char *name, eARCONTROLLER_ERROR error, void *customData);
void ARCONTROLLER_JNI_Device_CommandReceived (eARCONTROLLER_DICTIONARY_KEY commandKey, ARCONTROLLER_DICTIONARY_ELEMENT_t *elementDictionary, void *customData);
jobject ARCONTROLLER_JNI_Device_NewH264Codec (JNIEnv *env, ARCONTROLLER_Stream_Codec_t codec);
jobject ARCONTROLLER_JNI_Device_NewMJPEGCodec (JNIEnv *env, ARCONTROLLER_Stream_Codec_t codec);

eARCONTROLLER_ERROR ARCONTROLLER_JNI_Device_DecoderConfigCallback (ARCONTROLLER_Stream_Codec_t codec, void *customData);
eARCONTROLLER_ERROR ARCONTROLLER_JNI_Device_DidReceiveFrameCallback (ARCONTROLLER_Frame_t *frame, void *customData);
void ARCONTROLLER_JNI_Device_TimeoutFrameCallback (void *customData);

/*****************************************
 *
 *             implementation :
 *
 *****************************************/

static JavaVM* ARCONTROLLER_JNIDEVICE_VM = NULL; /** reference to the java virtual machine */

/**
 * @brief save the reference to the java virtual machine
 * @note this function is automatically call on the JNI startup
 * @param[in] VM reference to the java virtual machine
 * @param[in] reserved data reserved
 * @return JNI version
 */
JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *VM, void *reserved)
{
    ARSAL_PRINT(ARSAL_PRINT_DEBUG, ARCONTROLLER_JNIDEVICE_TAG, "Library has been loaded");

    /* Saving the reference to the java virtual machine */
    ARCONTROLLER_JNIDEVICE_VM = VM;

    /* Return the JNI version */
    return JNI_VERSION_1_6;
}

JNIEXPORT void JNICALL
Java_com_parrot_arsdk_arcontroller_ARDeviceController_nativeStaticInit (JNIEnv *env, jclass class)
{    
    // local declarations
    jclass jARDeviceControllerCls = NULL;
    
    // get ARDeviceController
    jARDeviceControllerCls = (*env)->FindClass(env, "com/parrot/arsdk/arcontroller/ARDeviceController");
    
    ARCONTROLLER_JNIDEVICE_METHOD_ON_STATE_CHANGED = (*env)->GetMethodID (env, jARDeviceControllerCls, "onStateChanged", "(II)V");
    ARCONTROLLER_JNIDEVICE_METHOD_ON_EXTENSION_STATE_CHANGED = (*env)->GetMethodID (env, jARDeviceControllerCls, "onExtensionStateChanged", "(IILjava/lang/String;I)V");
    ARCONTROLLER_JNIDEVICE_METHOD_DECODER_CONFIG_CALLBACK = (*env)->GetMethodID (env, jARDeviceControllerCls, "decoderConfigCallback", "(Lcom/parrot/arsdk/arcontroller/ARControllerCodec;)I");
    ARCONTROLLER_JNIDEVICE_METHOD_DID_RECEIVE_FRAME_CALLBACK = (*env)->GetMethodID (env, jARDeviceControllerCls, "didReceiveFrameCallback", "(JIIII)I");
    ARCONTROLLER_JNIDEVICE_METHOD_TIMEOUT_FRAME_CALLBACK = (*env)->GetMethodID (env, jARDeviceControllerCls, "timeoutFrameCallback", "()V");    
    ARCONTROLLER_JNIDEVICE_METHOD_ON_COMMAND_RECEIVED = (*env)->GetMethodID (env, jARDeviceControllerCls, "onCommandReceived", "(IJ)V");    
    
    // cleanup
    (*env)->DeleteLocalRef (env, jARDeviceControllerCls);
    
    //Get jARControllerCodecH264Cls
    jARControllerCodecH264Cls = (*env)->FindClass(env, "com/parrot/arsdk/arcontroller/ARControllerCodec$H264");
    ARCONTROLLER_JNIDEVICE_METHOD_NEW_CODEC_H264 = (*env)->GetMethodID(env, jARControllerCodecH264Cls, "<init>", "(JIJI)V");
    
    jARControllerCodecH264Cls = (*env)->NewGlobalRef (env, jARControllerCodecH264Cls);
    
    //Get jARControllerCodecMJPEGCls
    jARControllerCodecMJPEGCls = (*env)->FindClass(env, "com/parrot/arsdk/arcontroller/ARControllerCodec$Mjpeg");
    ARCONTROLLER_JNIDEVICE_METHOD_NEW_CODEC_MJPEG = (*env)->GetMethodID(env, jARControllerCodecMJPEGCls, "<init>", "()V");
    
    jARControllerCodecMJPEGCls = (*env)->NewGlobalRef (env, jARControllerCodecMJPEGCls);
    
}

/**
 * @brief Create and initialize a new device
 * @param env reference to the java environment
 * @param thizz reference to the object calling this function
 * @return new jni device object
 */
JNIEXPORT jlong JNICALL
Java_com_parrot_arsdk_arcontroller_ARDeviceController_nativeNew (JNIEnv *env, jobject thizz, jlong jDevice)
{
    // -- Create the Device --

    // local declarations
    eARCONTROLLER_ERROR error = ARCONTROLLER_OK;
    //ARCONTROLLER_Device_t *deviceController = NULL;
    ARCONTROLLER_JNIDeviceController_t *jniDeviceController = NULL;
    ARDISCOVERY_Device_t *device = (ARDISCOVERY_Device_t*) (intptr_t) jDevice;

    jclass exceptionCls = NULL;
    jmethodID exceptionMethodInit = NULL;
    jthrowable exception = NULL;

    // allocate the JNI Device Controller
    jniDeviceController = ARCONTROLLER_JNI_Device_NewJNIDeviceController (env, thizz, device, &error);
    
    if (error == ARCONTROLLER_OK)
    {
        error = ARCONTROLLER_Device_AddStateChangedCallback (jniDeviceController->nativeDeviceController, ARCONTROLLER_JNI_Device_StateChanged, jniDeviceController);
    }
    
    if (error == ARCONTROLLER_OK)
    {
        error = ARCONTROLLER_Device_AddExtensionStateChangedCallback (jniDeviceController->nativeDeviceController, ARCONTROLLER_JNI_Device_ExtensionStateChanged, jniDeviceController);
    }

    if (error == ARCONTROLLER_OK)
    {
        error = ARCONTROLLER_Device_AddCommandReceivedCallback (jniDeviceController->nativeDeviceController, ARCONTROLLER_JNI_Device_CommandReceived, jniDeviceController);
    }
    
    if (error == ARCONTROLLER_OK)
    {
        error = ARCONTROLLER_Device_SetVideoStreamCallbacks (jniDeviceController->nativeDeviceController, ARCONTROLLER_JNI_Device_DecoderConfigCallback, ARCONTROLLER_JNI_Device_DidReceiveFrameCallback, ARCONTROLLER_JNI_Device_TimeoutFrameCallback , jniDeviceController);
        if(error == ARCONTROLLER_ERROR_NO_VIDEO)
        {
            ARSAL_PRINT(ARSAL_PRINT_INFO, ARCONTROLLER_JNIDEVICE_TAG, "This device has no video stream");
            error = ARCONTROLLER_OK;
        }
    }

    if (error != ARCONTROLLER_OK)
    {
        // Delete the JNI device controller
        ARCONTROLLER_JNI_Device_DeleteJNIDeviceController (env, &jniDeviceController);
        
        // throw the exception
        exceptionCls = (*env)->FindClass(env, "com/parrot/arsdk/arcontroller/ARControllerException");
        exceptionMethodInit = (*env)->GetMethodID(env, exceptionCls, "<init>", "(I)V");
        exception = (*env)->NewObject(env, exceptionCls, exceptionMethodInit, error);
        (*env)->Throw(env, exception);
    }

    return (long) jniDeviceController;
}

/**
 * @brief delete the Device
 * @param env reference to the java environment
 * @param thizz reference to the object calling this function
 * @param jDevice the ARCONTROLLER_Device_t to delete
 */
JNIEXPORT void JNICALL
Java_com_parrot_arsdk_arcontroller_ARDeviceController_nativeDelete (JNIEnv *env, jobject thizz, jlong jDeviceController)
{
    // -- Delete the DeviceController --

    // local declarations
    ARCONTROLLER_JNIDeviceController_t *jniDeviceController = (ARCONTROLLER_JNIDeviceController_t*) (intptr_t) jDeviceController;

    ARCONTROLLER_JNI_Device_DeleteJNIDeviceController (env, &jniDeviceController);
}

JNIEXPORT jint JNICALL
Java_com_parrot_arsdk_arcontroller_ARDeviceController_nativeStart (JNIEnv *env, jobject thizz, jlong jDeviceController)
{
    // local declarations
    ARCONTROLLER_JNIDeviceController_t *jniDeviceController = (ARCONTROLLER_JNIDeviceController_t*) (intptr_t) jDeviceController;
    
    return ARCONTROLLER_Device_Start (jniDeviceController->nativeDeviceController);
}

JNIEXPORT jint JNICALL
Java_com_parrot_arsdk_arcontroller_ARDeviceController_nativeStop (JNIEnv *env, jobject thizz, jlong jDeviceController)
{
    // local declarations
    ARCONTROLLER_JNIDeviceController_t *jniDeviceController = (ARCONTROLLER_JNIDeviceController_t*) (intptr_t) jDeviceController;

    return ARCONTROLLER_Device_Stop (jniDeviceController->nativeDeviceController);
}

JNIEXPORT jlong JNICALL
Java_com_parrot_arsdk_arcontroller_ARDeviceController_nativeGetFeatureGeneric (JNIEnv *env, jobject thizz, jlong jDeviceController)
{
    // local declarations
    ARCONTROLLER_JNIDeviceController_t *jniDeviceController = (ARCONTROLLER_JNIDeviceController_t*) (intptr_t) jDeviceController;

    return (long) jniDeviceController->nativeDeviceController->generic;
}

JNIEXPORT jlong JNICALL
Java_com_parrot_arsdk_arcontroller_ARDeviceController_nativeGetFeatureARDrone3 (JNIEnv *env, jobject thizz, jlong jDeviceController)
{
    // local declarations
    ARCONTROLLER_JNIDeviceController_t *jniDeviceController = (ARCONTROLLER_JNIDeviceController_t*) (intptr_t) jDeviceController;

    return (long) jniDeviceController->nativeDeviceController->aRDrone3;
}

JNIEXPORT jlong JNICALL
Java_com_parrot_arsdk_arcontroller_ARDeviceController_nativeGetFeatureCommon (JNIEnv *env, jobject thizz, jlong jDeviceController)
{
    // local declarations
    ARCONTROLLER_JNIDeviceController_t *jniDeviceController = (ARCONTROLLER_JNIDeviceController_t*) (intptr_t) jDeviceController;

    return (long) jniDeviceController->nativeDeviceController->common;
}

JNIEXPORT jlong JNICALL
Java_com_parrot_arsdk_arcontroller_ARDeviceController_nativeGetFeatureCommonDebug (JNIEnv *env, jobject thizz, jlong jDeviceController)
{
    // local declarations
    ARCONTROLLER_JNIDeviceController_t *jniDeviceController = (ARCONTROLLER_JNIDeviceController_t*) (intptr_t) jDeviceController;

    return (long) jniDeviceController->nativeDeviceController->commonDebug;
}

JNIEXPORT jlong JNICALL
Java_com_parrot_arsdk_arcontroller_ARDeviceController_nativeGetFeatureFollowMe (JNIEnv *env, jobject thizz, jlong jDeviceController)
{
    // local declarations
    ARCONTROLLER_JNIDeviceController_t *jniDeviceController = (ARCONTROLLER_JNIDeviceController_t*) (intptr_t) jDeviceController;

    return (long) jniDeviceController->nativeDeviceController->follow_me;
}

JNIEXPORT jlong JNICALL
Java_com_parrot_arsdk_arcontroller_ARDeviceController_nativeGetFeatureJumpingSumo (JNIEnv *env, jobject thizz, jlong jDeviceController)
{
    // local declarations
    ARCONTROLLER_JNIDeviceController_t *jniDeviceController = (ARCONTROLLER_JNIDeviceController_t*) (intptr_t) jDeviceController;

    return (long) jniDeviceController->nativeDeviceController->jumpingSumo;
}

JNIEXPORT jlong JNICALL
Java_com_parrot_arsdk_arcontroller_ARDeviceController_nativeGetFeatureMiniDrone (JNIEnv *env, jobject thizz, jlong jDeviceController)
{
    // local declarations
    ARCONTROLLER_JNIDeviceController_t *jniDeviceController = (ARCONTROLLER_JNIDeviceController_t*) (intptr_t) jDeviceController;

    return (long) jniDeviceController->nativeDeviceController->miniDrone;
}

JNIEXPORT jlong JNICALL
Java_com_parrot_arsdk_arcontroller_ARDeviceController_nativeGetFeaturePro (JNIEnv *env, jobject thizz, jlong jDeviceController)
{
    // local declarations
    ARCONTROLLER_JNIDeviceController_t *jniDeviceController = (ARCONTROLLER_JNIDeviceController_t*) (intptr_t) jDeviceController;

    return (long) jniDeviceController->nativeDeviceController->pro;
}

JNIEXPORT jlong JNICALL
Java_com_parrot_arsdk_arcontroller_ARDeviceController_nativeGetFeatureSkyController (JNIEnv *env, jobject thizz, jlong jDeviceController)
{
    // local declarations
    ARCONTROLLER_JNIDeviceController_t *jniDeviceController = (ARCONTROLLER_JNIDeviceController_t*) (intptr_t) jDeviceController;

    return (long) jniDeviceController->nativeDeviceController->skyController;
}

JNIEXPORT jlong JNICALL
Java_com_parrot_arsdk_arcontroller_ARDeviceController_nativeGetFeatureWifi (JNIEnv *env, jobject thizz, jlong jDeviceController)
{
    // local declarations
    ARCONTROLLER_JNIDeviceController_t *jniDeviceController = (ARCONTROLLER_JNIDeviceController_t*) (intptr_t) jDeviceController;

    return (long) jniDeviceController->nativeDeviceController->wifi;
}

JNIEXPORT jlong JNICALL
Java_com_parrot_arsdk_arcontroller_ARDeviceController_nativeGetCommandElements (JNIEnv *env, jobject thizz, jlong jDeviceController, jint commandKey)
{
    // local declarations
    ARCONTROLLER_JNIDeviceController_t *jniDeviceController = (ARCONTROLLER_JNIDeviceController_t*) (intptr_t) jDeviceController;
    eARCONTROLLER_ERROR error = ARCONTROLLER_OK;
    ARCONTROLLER_DICTIONARY_ELEMENT_t *elements = NULL;

    jclass exceptionCls = NULL;
    jmethodID exceptionMethodInit = NULL;
    jthrowable exception = NULL;

    elements = ARCONTROLLER_Device_GetCommandElements (jniDeviceController->nativeDeviceController, commandKey, &error);

    if (error != ARCONTROLLER_OK)
    {
        // throw the exception
        exceptionCls = (*env)->FindClass(env, "com/parrot/arsdk/arcontroller/ARControllerException");
        exceptionMethodInit = (*env)->GetMethodID(env, exceptionCls, "<init>", "(I)V");
        exception = (*env)->NewObject(env, exceptionCls, exceptionMethodInit, error);
        (*env)->Throw(env, exception);
    }

    return (long) elements;
}

JNIEXPORT jint JNICALL
Java_com_parrot_arsdk_arcontroller_ARDeviceController_nativeGetState (JNIEnv *env, jobject thizz, jlong jDeviceController)
{
    // local declarations
    ARCONTROLLER_JNIDeviceController_t *jniDeviceController = (ARCONTROLLER_JNIDeviceController_t*) (intptr_t) jDeviceController;
    eARCONTROLLER_ERROR error = ARCONTROLLER_OK;
    eARCONTROLLER_DEVICE_STATE state = ARCONTROLLER_DEVICE_STATE_MAX;

    jclass exceptionCls = NULL;
    jmethodID exceptionMethodInit = NULL;
    jthrowable exception = NULL;

    state = ARCONTROLLER_Device_GetState (jniDeviceController->nativeDeviceController, &error);

    if (error != ARCONTROLLER_OK)
    {
        // throw the exception
        exceptionCls = (*env)->FindClass(env, "com/parrot/arsdk/arcontroller/ARControllerException");
        exceptionMethodInit = (*env)->GetMethodID(env, exceptionCls, "<init>", "(I)V");
        exception = (*env)->NewObject(env, exceptionCls, exceptionMethodInit, error);
        (*env)->Throw(env, exception);
    }

    return state;
}

JNIEXPORT jint JNICALL
Java_com_parrot_arsdk_arcontroller_ARDeviceController_nativeGetExtensionState (JNIEnv *env, jobject thizz, jlong jDeviceController)
{
    // local declarations
    ARCONTROLLER_JNIDeviceController_t *jniDeviceController = (ARCONTROLLER_JNIDeviceController_t*) (intptr_t) jDeviceController;
    eARCONTROLLER_ERROR error = ARCONTROLLER_OK;
    eARCONTROLLER_DEVICE_STATE extensionState = ARCONTROLLER_DEVICE_STATE_MAX;
    
    jclass exceptionCls = NULL;
    jmethodID exceptionMethodInit = NULL;
    jthrowable exception = NULL;
    
    extensionState = ARCONTROLLER_Device_GetExtensionState (jniDeviceController->nativeDeviceController, &error);
    
    if (error != ARCONTROLLER_OK)
    {
        // throw the exception
        exceptionCls = (*env)->FindClass(env, "com/parrot/arsdk/arcontroller/ARControllerException");
        exceptionMethodInit = (*env)->GetMethodID(env, exceptionCls, "<init>", "(I)V");
        exception = (*env)->NewObject(env, exceptionCls, exceptionMethodInit, error);
        (*env)->Throw(env, exception);
    }
    
    return extensionState;
}

JNIEXPORT jstring JNICALL
Java_com_parrot_arsdk_arcontroller_ARDeviceController_nativeGetExtensionName (JNIEnv *env, jobject thizz, jlong jDeviceController)
{
    // local declarations
    ARCONTROLLER_JNIDeviceController_t *jniDeviceController = (ARCONTROLLER_JNIDeviceController_t*) (intptr_t) jDeviceController;
    eARCONTROLLER_ERROR error = ARCONTROLLER_OK;
    jstring extensionNameStr = NULL;
    
    jclass exceptionCls = NULL;
    jmethodID exceptionMethodInit = NULL;
    jthrowable exception = NULL;
    
    char extensionNameBuffer[128];
    ARCONTROLLER_Device_GetExtensionName (jniDeviceController->nativeDeviceController, extensionNameBuffer, 128, &error);
    
    if (error != ARCONTROLLER_OK)
    {
        // throw the exception
        exceptionCls = (*env)->FindClass(env, "com/parrot/arsdk/arcontroller/ARControllerException");
        exceptionMethodInit = (*env)->GetMethodID(env, exceptionCls, "<init>", "(I)V");
        exception = (*env)->NewObject(env, exceptionCls, exceptionMethodInit, error);
        (*env)->Throw(env, exception);
    }
    else
    {
        extensionNameStr = (*env)->NewStringUTF(env, extensionNameBuffer);
    }
    
    return extensionNameStr;
}

JNIEXPORT jint JNICALL
Java_com_parrot_arsdk_arcontroller_ARDeviceController_nativeGetExtensionProduct (JNIEnv *env, jobject thizz, jlong jDeviceController)
{
    // local declarations
    ARCONTROLLER_JNIDeviceController_t *jniDeviceController = (ARCONTROLLER_JNIDeviceController_t*) (intptr_t) jDeviceController;
    eARCONTROLLER_ERROR error = ARCONTROLLER_OK;
    eARDISCOVERY_PRODUCT extensionProduct = ARDISCOVERY_PRODUCT_MAX;
    
    jclass exceptionCls = NULL;
    jmethodID exceptionMethodInit = NULL;
    jthrowable exception = NULL;
    
    extensionProduct = ARCONTROLLER_Device_GetExtensionProduct (jniDeviceController->nativeDeviceController, &error);
    
    if (error != ARCONTROLLER_OK)
    {
        // throw the exception
        exceptionCls = (*env)->FindClass(env, "com/parrot/arsdk/arcontroller/ARControllerException");
        exceptionMethodInit = (*env)->GetMethodID(env, exceptionCls, "<init>", "(I)V");
        exception = (*env)->NewObject(env, exceptionCls, exceptionMethodInit, error);
        (*env)->Throw(env, exception);
    }
    
    return extensionProduct;
}

/*****************************************
 *
 *             private implementation:
 *
 *****************************************/

ARCONTROLLER_JNIDeviceController_t *ARCONTROLLER_JNI_Device_NewJNIDeviceController (JNIEnv *env, jobject thizz, ARDISCOVERY_Device_t *discoveryDevice, eARCONTROLLER_ERROR *error)
{
    ARCONTROLLER_JNIDeviceController_t *jniDeviceController = malloc (sizeof (ARCONTROLLER_JNIDeviceController_t));
    
    if (jniDeviceController != NULL)
    {
        // Create a new native deviceController
        jniDeviceController->nativeDeviceController = ARCONTROLLER_Device_New (discoveryDevice, error);
        
        // create a global reference of the java object
        jniDeviceController->jDeviceController = (*env)->NewGlobalRef (env, thizz);
    }
    else if (error != NULL)
    {
        *error = ARCONTROLLER_ERROR_ALLOC;
    }
    
    return jniDeviceController;
}

void ARCONTROLLER_JNI_Device_DeleteJNIDeviceController (JNIEnv *env, ARCONTROLLER_JNIDeviceController_t **jniDeviceController)
{
    if (jniDeviceController != NULL)
    {
        if ((*jniDeviceController) != NULL)
        {
            // Delete native deviceController
            ARCONTROLLER_Device_Delete (&((*jniDeviceController)->nativeDeviceController));
            
            // Delete global references
            (*env)->DeleteGlobalRef (env, (*jniDeviceController)->jDeviceController);
            (*jniDeviceController)->jDeviceController = NULL;
            
            free (*jniDeviceController);
            (*jniDeviceController) = NULL;
        }
    }
}

// called when the state of the device controller has changed
void ARCONTROLLER_JNI_Device_StateChanged (eARCONTROLLER_DEVICE_STATE newState, eARCONTROLLER_ERROR error, void *customData)
{
    // local declarations
    eARCONTROLLER_ERROR localError = ARCONTROLLER_OK;
    JNIEnv* env = NULL;
    jint getEnvResult = JNI_OK;
    jint attachResult = 1;
    
    ARCONTROLLER_JNIDeviceController_t *jniDeviceController = (ARCONTROLLER_JNIDeviceController_t*) (intptr_t) customData;
        
    if ((jniDeviceController == NULL) ||
        (jniDeviceController->jDeviceController == NULL))
    {
        localError = ARCONTROLLER_ERROR_BAD_PARAMETER;
    }
    
    if (localError == ARCONTROLLER_OK)
    {
        // get the environment
        getEnvResult = (*ARCONTROLLER_JNIDEVICE_VM)->GetEnv(ARCONTROLLER_JNIDEVICE_VM, (void **) &env, JNI_VERSION_1_6);

        // if no environment then attach the thread to the virtual machine
        if (getEnvResult == JNI_EDETACHED)
        {
            ARSAL_PRINT(ARSAL_PRINT_DEBUG, ARCONTROLLER_JNIDEVICE_TAG, "attach the thread to the virtual machine ...");
            attachResult = (*ARCONTROLLER_JNIDEVICE_VM)->AttachCurrentThread(ARCONTROLLER_JNIDEVICE_VM, &env, NULL);
        }

        if (env == NULL)
        {
            localError = ARCONTROLLER_ERROR_JNI_ENV;
        }
    }
    
    if (localError == ARCONTROLLER_OK)
    {
        // java onStateChanged callback
        (*env)->CallVoidMethod(env, jniDeviceController->jDeviceController, ARCONTROLLER_JNIDEVICE_METHOD_ON_STATE_CHANGED, newState, error);
    }
    
    // if the thread has been attached then detach the thread from the virtual machine
    if ((getEnvResult == JNI_EDETACHED) && (env != NULL))
    {
        (*ARCONTROLLER_JNIDEVICE_VM)->DetachCurrentThread(ARCONTROLLER_JNIDEVICE_VM);
    }
}

// called when the state of the extension has changed
void ARCONTROLLER_JNI_Device_ExtensionStateChanged (eARCONTROLLER_DEVICE_STATE newState, eARDISCOVERY_PRODUCT product, const char *name, eARCONTROLLER_ERROR error, void *customData)
{
    // local declarations
    eARCONTROLLER_ERROR localError = ARCONTROLLER_OK;
    JNIEnv* env = NULL;
    jint getEnvResult = JNI_OK;
    jint attachResult = 1;
    jstring extensionNameStr = NULL;
    
    ARCONTROLLER_JNIDeviceController_t *jniDeviceController = (ARCONTROLLER_JNIDeviceController_t*) (intptr_t) customData;
    
    if ((jniDeviceController == NULL) ||
        (jniDeviceController->jDeviceController == NULL))
    {
        localError = ARCONTROLLER_ERROR_BAD_PARAMETER;
    }
        
    if (localError == ARCONTROLLER_OK)
    {
        // get the environment
        getEnvResult = (*ARCONTROLLER_JNIDEVICE_VM)->GetEnv(ARCONTROLLER_JNIDEVICE_VM, (void **) &env, JNI_VERSION_1_6);
        
        // if no environment then attach the thread to the virtual machine
        if (getEnvResult == JNI_EDETACHED)
        {
            ARSAL_PRINT(ARSAL_PRINT_DEBUG, ARCONTROLLER_JNIDEVICE_TAG, "attach the thread to the virtual machine ...");
            attachResult = (*ARCONTROLLER_JNIDEVICE_VM)->AttachCurrentThread(ARCONTROLLER_JNIDEVICE_VM, &env, NULL);
        }
        
        if (env == NULL)
        {
            localError = ARCONTROLLER_ERROR_JNI_ENV;
        }
    }
    
    if (localError == ARCONTROLLER_OK)
    {
        extensionNameStr = (*env)->NewStringUTF(env, name);
        // java onStateChanged callback
        (*env)->CallVoidMethod(env, jniDeviceController->jDeviceController, ARCONTROLLER_JNIDEVICE_METHOD_ON_EXTENSION_STATE_CHANGED, newState, product, extensionNameStr, error);
    }
    
    // if the thread has been attached then detach the thread from the virtual machine
    if ((getEnvResult == JNI_EDETACHED) && (env != NULL))
    {
        (*ARCONTROLLER_JNIDEVICE_VM)->DetachCurrentThread(ARCONTROLLER_JNIDEVICE_VM);
    }
}

// called when a command has been received from the drone
void ARCONTROLLER_JNI_Device_CommandReceived (eARCONTROLLER_DICTIONARY_KEY commandKey, ARCONTROLLER_DICTIONARY_ELEMENT_t *elementDictionary, void *customData)
{
    // local declarations
    eARCONTROLLER_ERROR localError = ARCONTROLLER_OK;
    JNIEnv* env = NULL;
    jint getEnvResult = JNI_OK;
    jint attachResult = 1;
    
    ARCONTROLLER_JNIDeviceController_t *jniDeviceController = (ARCONTROLLER_JNIDeviceController_t*) (intptr_t) customData;
    eARCONTROLLER_ERROR error = ARCONTROLLER_OK;
    
    if ((jniDeviceController == NULL) ||
        (jniDeviceController->jDeviceController == NULL))
    {
        localError = ARCONTROLLER_ERROR_BAD_PARAMETER;
    }
    
    if (localError == ARCONTROLLER_OK)
    {
        // get the environment
        getEnvResult = (*ARCONTROLLER_JNIDEVICE_VM)->GetEnv(ARCONTROLLER_JNIDEVICE_VM, (void **) &env, JNI_VERSION_1_6);

        // if no environment then attach the thread to the virtual machine
        if (getEnvResult == JNI_EDETACHED)
        {
            ARSAL_PRINT(ARSAL_PRINT_DEBUG, ARCONTROLLER_JNIDEVICE_TAG, "attach the thread to the virtual machine ...");
            attachResult = (*ARCONTROLLER_JNIDEVICE_VM)->AttachCurrentThread(ARCONTROLLER_JNIDEVICE_VM, &env, NULL);
        }

        if (env == NULL)
        {
            localError = ARCONTROLLER_ERROR_JNI_ENV;
        }
    }
    
    if (localError == ARCONTROLLER_OK)
    {
        // java onCommandReceived callback
        (*env)->CallVoidMethod(env, jniDeviceController->jDeviceController, ARCONTROLLER_JNIDEVICE_METHOD_ON_COMMAND_RECEIVED, commandKey, (long) elementDictionary);
    }
    
    // if the thread has been attached then detach the thread from the virtual machine
    if ((getEnvResult == JNI_EDETACHED) && (env != NULL))
    {
        (*ARCONTROLLER_JNIDEVICE_VM)->DetachCurrentThread(ARCONTROLLER_JNIDEVICE_VM);
    }
}

eARCONTROLLER_ERROR ARCONTROLLER_JNI_Device_DecoderConfigCallback (ARCONTROLLER_Stream_Codec_t codec, void *customData)
{
    
    // local declarations
    eARCONTROLLER_ERROR localError = ARCONTROLLER_OK;
    JNIEnv* env = NULL;
    jint getEnvResult = JNI_OK;
    jint attachResult = 1;
    jobject jCodec = NULL;
    
    eARCONTROLLER_ERROR callbackError = ARCONTROLLER_OK;
    
    ARCONTROLLER_JNIDeviceController_t *jniDeviceController = (ARCONTROLLER_JNIDeviceController_t*) (intptr_t) customData;
    
    if ((jniDeviceController == NULL) ||
        (jniDeviceController->jDeviceController == NULL))
    {
        localError = ARCONTROLLER_ERROR_BAD_PARAMETER;
    }
    
    if (localError == ARCONTROLLER_OK)
    {
        // get the environment
        getEnvResult = (*ARCONTROLLER_JNIDEVICE_VM)->GetEnv(ARCONTROLLER_JNIDEVICE_VM, (void **) &env, JNI_VERSION_1_6);
        
        // if no environment then attach the thread to the virtual machine
        if (getEnvResult == JNI_EDETACHED)
        {
            ARSAL_PRINT(ARSAL_PRINT_DEBUG, ARCONTROLLER_JNIDEVICE_TAG, "attach the thread to the virtual machine ...");
            attachResult = (*ARCONTROLLER_JNIDEVICE_VM)->AttachCurrentThread(ARCONTROLLER_JNIDEVICE_VM, &env, NULL);
        }
        
        if (env == NULL)
        {
            localError = ARCONTROLLER_ERROR_JNI_ENV;
        }
    }
    
    if (localError == ARCONTROLLER_OK)
    {
        switch(codec.type)
        {
            case ARCONTROLLER_STREAM_CODEC_TYPE_H264:
                jCodec = ARCONTROLLER_JNI_Device_NewH264Codec(env, codec);
                break;
            
            case ARCONTROLLER_STREAM_CODEC_TYPE_MJPEG:
                jCodec = ARCONTROLLER_JNI_Device_NewMJPEGCodec(env, codec);
                break;
            
            default:
                ARSAL_PRINT(ARSAL_PRINT_WARNING, ARCONTROLLER_JNIDEVICE_TAG, "Unknown codec: %d", codec.type);
                break;
        }
        
        // java decoderConfigCallback callback
        callbackError = (*env)->CallIntMethod(env, jniDeviceController->jDeviceController, ARCONTROLLER_JNIDEVICE_METHOD_DECODER_CONFIG_CALLBACK, jCodec);
    }
    
    // if the thread has been attached then detach the thread from the virtual machine
    if ((getEnvResult == JNI_EDETACHED) && (env != NULL))
    {
        (*ARCONTROLLER_JNIDEVICE_VM)->DetachCurrentThread(ARCONTROLLER_JNIDEVICE_VM);
    }
    
    return callbackError;
}

jobject ARCONTROLLER_JNI_Device_NewH264Codec (JNIEnv *env, ARCONTROLLER_Stream_Codec_t codec)
{
    // local declarations
    eARCONTROLLER_ERROR localError = ARCONTROLLER_OK;
    jlong spsBuffer = (intptr_t) codec.parameters.h264parameters.spsBuffer;
    jint spsSize =  codec.parameters.h264parameters.spsSize;
    
    jlong ppsBuffer = (intptr_t) codec.parameters.h264parameters.ppsBuffer;
    jint ppsSize =  codec.parameters.h264parameters.ppsSize;
    
    jobject jCodecH264 = (*env)->NewObject(env, jARControllerCodecH264Cls, ARCONTROLLER_JNIDEVICE_METHOD_NEW_CODEC_H264, spsBuffer, spsSize, ppsBuffer, ppsSize);
    
    return jCodecH264;
}

jobject ARCONTROLLER_JNI_Device_NewMJPEGCodec (JNIEnv *env, ARCONTROLLER_Stream_Codec_t codec)
{
    // local declarations
    eARCONTROLLER_ERROR localError = ARCONTROLLER_OK;
    
    jobject jCodecMJPEG = (*env)->NewObject(env, jARControllerCodecMJPEGCls, ARCONTROLLER_JNIDEVICE_METHOD_NEW_CODEC_MJPEG);
    
    return jCodecMJPEG;
}

eARCONTROLLER_ERROR ARCONTROLLER_JNI_Device_DidReceiveFrameCallback (ARCONTROLLER_Frame_t *frame, void *customData)
{
    // local declarations
    eARCONTROLLER_ERROR localError = ARCONTROLLER_OK;
    JNIEnv* env = NULL;
    jint getEnvResult = JNI_OK;
    jint attachResult = 1;
    
    jlong data = 0;
    jint dataCapacity = 0;
    jint dataSize = 0;
    jint isIFrame = 0;
    jint missed = 0;
    
    eARCONTROLLER_ERROR callbackError = ARCONTROLLER_OK;
    
    ARCONTROLLER_JNIDeviceController_t *jniDeviceController = (ARCONTROLLER_JNIDeviceController_t*) (intptr_t) customData;
        
    if ((jniDeviceController == NULL) ||
        (jniDeviceController->jDeviceController == NULL))
    {
        localError = ARCONTROLLER_ERROR_BAD_PARAMETER;
    }
    
    if (localError == ARCONTROLLER_OK)
    {
        // get the environment
        getEnvResult = (*ARCONTROLLER_JNIDEVICE_VM)->GetEnv(ARCONTROLLER_JNIDEVICE_VM, (void **) &env, JNI_VERSION_1_6);

        // if no environment then attach the thread to the virtual machine
        if (getEnvResult == JNI_EDETACHED)
        {
            ARSAL_PRINT(ARSAL_PRINT_DEBUG, ARCONTROLLER_JNIDEVICE_TAG, "attach the thread to the virtual machine ...");
            attachResult = (*ARCONTROLLER_JNIDEVICE_VM)->AttachCurrentThread(ARCONTROLLER_JNIDEVICE_VM, &env, NULL);
        }

        if (env == NULL)
        {
            localError = ARCONTROLLER_ERROR_JNI_ENV;
        }
    }
    
    if (localError == ARCONTROLLER_OK)
    {
        
        if (frame != NULL)
        {
            data = (long)frame->data;
            dataCapacity = frame->capacity;
            dataSize = frame->used;
            isIFrame = frame->isIFrame;
            missed = frame->missed;
        }
        
        // java did receive frame callback
        callbackError = (*env)->CallIntMethod(env, jniDeviceController->jDeviceController, ARCONTROLLER_JNIDEVICE_METHOD_DID_RECEIVE_FRAME_CALLBACK, data, dataCapacity, dataSize, isIFrame, missed);
    }
    
    // if the thread has been attached then detach the thread from the virtual machine
    if ((getEnvResult == JNI_EDETACHED) && (env != NULL))
    {
        (*ARCONTROLLER_JNIDEVICE_VM)->DetachCurrentThread(ARCONTROLLER_JNIDEVICE_VM);
    }
    
    return callbackError;
}

void ARCONTROLLER_JNI_Device_TimeoutFrameCallback (void *customData)
{
    // local declarations
    eARCONTROLLER_ERROR localError = ARCONTROLLER_OK;
    JNIEnv* env = NULL;
    jint getEnvResult = JNI_OK;
    jint attachResult = 1;
    
    ARCONTROLLER_JNIDeviceController_t *jniDeviceController = (ARCONTROLLER_JNIDeviceController_t*) (intptr_t) customData;
        
    if ((jniDeviceController == NULL) ||
        (jniDeviceController->jDeviceController == NULL))
    {
        localError = ARCONTROLLER_ERROR_BAD_PARAMETER;
    }
    
    if (localError == ARCONTROLLER_OK)
    {
        // get the environment
        getEnvResult = (*ARCONTROLLER_JNIDEVICE_VM)->GetEnv(ARCONTROLLER_JNIDEVICE_VM, (void **) &env, JNI_VERSION_1_6);

        // if no environment then attach the thread to the virtual machine
        if (getEnvResult == JNI_EDETACHED)
        {
            ARSAL_PRINT(ARSAL_PRINT_DEBUG, ARCONTROLLER_JNIDEVICE_TAG, "attach the thread to the virtual machine ...");
            attachResult = (*ARCONTROLLER_JNIDEVICE_VM)->AttachCurrentThread(ARCONTROLLER_JNIDEVICE_VM, &env, NULL);
        }

        if (env == NULL)
        {
            localError = ARCONTROLLER_ERROR_JNI_ENV;
        }
    }
    
    if (localError == ARCONTROLLER_OK)
    {
        // java onStateChanged callback
        (*env)->CallVoidMethod(env, jniDeviceController->jDeviceController, ARCONTROLLER_JNIDEVICE_METHOD_TIMEOUT_FRAME_CALLBACK);
    }
    
    // if the thread has been attached then detach the thread from the virtual machine
    if ((getEnvResult == JNI_EDETACHED) && (env != NULL))
    {
        (*ARCONTROLLER_JNIDEVICE_VM)->DetachCurrentThread(ARCONTROLLER_JNIDEVICE_VM);
    }
}

