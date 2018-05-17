// PnClientSDK.h

#ifndef __NR_CLIENT_SDK_H

#define __NR_CLIENT_SDK_H


#ifdef  NR_CLIENT_SDK_API
 #define NRCLIENTSDK_API  extern "C" __declspec(dllexport)
#else
 #define NRCLIENTSDK_API  extern "C" __declspec(dllimport)
#endif


#ifndef    NULL
 #define	   NULL 0
#endif


//标签定义
typedef struct _NRCLIENTSDK_CARD
{
   unsigned long  slot;           //分站号
   unsigned long  cardNo;         //卡号
   unsigned long  isLowPower;     //是否欠压
   int  distance;       //距离
}NRCLIENTSDK_CARD, *LNRCLIENTSDK_CARD;

//事件回调函数定义
//evt    事件
//devIp  网络读卡器IP
//card   读到的卡信息
typedef int (__stdcall  * NrClientSDK_Event_CallBack)(int evt, char * devIp, LNRCLIENTSDK_CARD card);


/********************************* 回调函数事件定义 evt *****************************************/                                                                                
#define EVENT_CONNECT_OK                     1    //连接成功                 
#define EVENT_DISCONNECT                     3    //断开连接                           
#define EVENT_CARD_READ                      4    //读取到标签信息                     


/*******错误值定义******/
#define NRCLIENTSDK_OK                            0     //OK
#define NRCLIENTSDK_ERR_READER_NOT_CONNECT        1    //读卡器未连接
#define NRCLIENTSDK_ERR_READER_TIMEOUT            2    //超时
#define NRCLIENTSDK_ERR_READER_ALREADY_EXIST      3    //读卡器已存在
#define NRCLIENTSDK_ERR_READER_READER_NOT_EXIST   4    //读卡器未存在
#define NRCLIENTSDK_ERR_SDK_NOT_INIT              5    //SDK未初始化
#define NRCLIENTSDK_ERR_PARAM_WRONG               6    //参数错误
#define NRCLIENTSDK_ERR_DEV_COUNT_REACH_MAX       7    //设备数量达到最大


/********************************SDK接口函数声明*********************************/
//初始化SDK
//参数   ver   [out]   SDK版本
//返回值  0 成功  非零：失败值
NRCLIENTSDK_API int __stdcall NrClientSDK_Init(char * ver, NrClientSDK_Event_CallBack eventCb);

//添加一个读卡器
//参数   devIp   读卡器的IP地址
//返回值  0 成功  非零：失败值
NRCLIENTSDK_API int __stdcall NrClientSDK_NewReader(char  * devIp);

//删除一个读卡器
//参数   devIp   读卡器的IP地址
//返回值  0 成功  非零：失败值
NRCLIENTSDK_API int __stdcall NrClientSDK_DelReader(char  * devIp);



#endif
