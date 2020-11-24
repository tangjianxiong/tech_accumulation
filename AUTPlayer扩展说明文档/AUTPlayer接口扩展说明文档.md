# 概述
## 文档说明
此文档为AUTPlayer模块接口扩展说明文档。
## 适用人员
在AUTPlayer接口上进行二次开发，且关注图像、声音和字幕底层接口可自定义的开发人员。

# 扩展详情
## 接口扩展说明
AUTPlayer播放器类的构造函数扩展了图像、声音、字幕的显示控制自定义指针，可按照《播控模块API说明文档》的规范指定自定义的底层接口，默认情况下使用XPlayer相关的底层显示接口。

```C
AUTPlayer(SoundCtrl* sound = NULL, LayerCtrl* layer = NULL, SubCtrl* sub = NULL);

```
## 使用说明
自定义的声音、图像和字母接口函数需要通过SoundCtrl、LayerCtrl和SubCtrl播控结构体指定相应的函数。

SoundCtrl详情如下,各个指针含义可参考《播控模块API说明文档》。

```c
typedef struct SoundCtrl SoundCtrl;
typedef struct SoundControlOpsS SoundControlOpsT;
struct SoundControlOpsS
{
    void (*destroy)(SoundCtrl* s);
    void (*setFormat)(SoundCtrl* s, CdxPlaybkCfg* cfg);
    int (*start)(SoundCtrl* s);
    int (*stop)(SoundCtrl* s);
    int (*pause)(SoundCtrl* s);
    int (*write)(SoundCtrl* s, void* pData, int nDataSize);
    int (*reset)(SoundCtrl* s);
    int (*getCachedTime)(SoundCtrl* s);
    int (*getFrameCount)(SoundCtrl* s);
    int (*setPlaybackRate)(SoundCtrl* s,const XAudioPlaybackRate *rate);
    int (*control)(SoundCtrl* s, int cmd, void* para);
};
```

LayerCtrl详情如下,各个指针含义可参考《播控模块API说明文档》。

```c
typedef struct LayerCtrl LayerCtrl;

typedef struct LayerControlOpsS
{
    void (*release)(LayerCtrl*);
    int (*setSecureFlag)(LayerCtrl*, int);
    int (*setDisplayBufferSize)(LayerCtrl* , int , int );
    int (*setDisplayBufferCount)(LayerCtrl* , int );
    int (*setDisplayRegion)(LayerCtrl* , int , int , int , int );
    int (*setDisplayPixelFormat)(LayerCtrl* , enum EPIXELFORMAT );
    int (*setVideoWithTwoStreamFlag)(LayerCtrl* , int );
    int (*setIsSoftDecoderFlag)(LayerCtrl* , int);
    int (*setBufferTimeStamp)(LayerCtrl* , int64_t );
    void (*resetNativeWindow)(LayerCtrl* ,void*);
    VideoPicture* (*getBufferOwnedByGpu)(LayerCtrl* );
    int (*getDisplayFPS)(LayerCtrl* );
    int (*getBufferNumHoldByGpu)(LayerCtrl* );
    int (*ctrlShowVideo)(LayerCtrl* );
    int (*ctrlHideVideo)(LayerCtrl*);
    int (*ctrlIsVideoShow)(LayerCtrl* );
    int (*ctrlHoldLastPicture)(LayerCtrl* , int );
    int (*dequeueBuffer)(LayerCtrl* , VideoPicture** , int);
    int (*queueBuffer)(LayerCtrl* , VideoPicture* , int);
    int (*releaseBuffer)(LayerCtrl* ,VideoPicture*);
    int (*reset)(LayerCtrl*);
    void (*destroy)(LayerCtrl*);
    int (*control)(LayerCtrl*, cdx_int32 , void *);
}LayerControlOpsT;

```

SubCtrl详情如下,各个指针含义可参考《播控模块API说明文档》。

```c
struct SubtitleControlOpsS
{
    int (*destory)(SubCtrl* p);
    int (*show)(SubCtrl* p, SubtitleItem *pItem, unsigned int id);
    int (*hide)(SubCtrl* p, unsigned int id);
};
```

## 使用示例
在应用代码中，创建自定义SoundCtrl、LayerCtrl和SubCtrl指针，并按照相应规范赋值，然后将三个指针赋值给AUTPlayer的构造函数即可。

```c
SoundCtrl* mSound;
SubCtrl* mSub;
LayerCtrl* mLayer;

//给相应函数指针赋值

AUTPlayer* player = new AUTPlayer(mSound, mLayer, mSub);
```

如不需要自定义相关接口，只需要正常创建AUTPlayer类即可，其他功能正常使用。

```c
AUTPlayer* player = new AUTPlayer();
```