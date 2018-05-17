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


//��ǩ����
typedef struct _NRCLIENTSDK_CARD
{
   unsigned long  slot;           //��վ��
   unsigned long  cardNo;         //����
   unsigned long  isLowPower;     //�Ƿ�Ƿѹ
   int  distance;       //����
}NRCLIENTSDK_CARD, *LNRCLIENTSDK_CARD;

//�¼��ص���������
//evt    �¼�
//devIp  ���������IP
//card   �����Ŀ���Ϣ
typedef int (__stdcall  * NrClientSDK_Event_CallBack)(int evt, char * devIp, LNRCLIENTSDK_CARD card);


/********************************* �ص������¼����� evt *****************************************/                                                                                
#define EVENT_CONNECT_OK                     1    //���ӳɹ�                 
#define EVENT_DISCONNECT                     3    //�Ͽ�����                           
#define EVENT_CARD_READ                      4    //��ȡ����ǩ��Ϣ                     


/*******����ֵ����******/
#define NRCLIENTSDK_OK                            0     //OK
#define NRCLIENTSDK_ERR_READER_NOT_CONNECT        1    //������δ����
#define NRCLIENTSDK_ERR_READER_TIMEOUT            2    //��ʱ
#define NRCLIENTSDK_ERR_READER_ALREADY_EXIST      3    //�������Ѵ���
#define NRCLIENTSDK_ERR_READER_READER_NOT_EXIST   4    //������δ����
#define NRCLIENTSDK_ERR_SDK_NOT_INIT              5    //SDKδ��ʼ��
#define NRCLIENTSDK_ERR_PARAM_WRONG               6    //��������
#define NRCLIENTSDK_ERR_DEV_COUNT_REACH_MAX       7    //�豸�����ﵽ���


/********************************SDK�ӿں�������*********************************/
//��ʼ��SDK
//����   ver   [out]   SDK�汾
//����ֵ  0 �ɹ�  ���㣺ʧ��ֵ
NRCLIENTSDK_API int __stdcall NrClientSDK_Init(char * ver, NrClientSDK_Event_CallBack eventCb);

//���һ��������
//����   devIp   ��������IP��ַ
//����ֵ  0 �ɹ�  ���㣺ʧ��ֵ
NRCLIENTSDK_API int __stdcall NrClientSDK_NewReader(char  * devIp);

//ɾ��һ��������
//����   devIp   ��������IP��ַ
//����ֵ  0 �ɹ�  ���㣺ʧ��ֵ
NRCLIENTSDK_API int __stdcall NrClientSDK_DelReader(char  * devIp);



#endif
