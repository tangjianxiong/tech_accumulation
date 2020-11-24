<!--
 * @Copyright(c) 2008 - 2021 Allwinner Technology Co. Ltd.
 * All rights reserved.
 * 
 * @CreateDate   : 2020-10-23
 * @Author       : Jianxiong Tang
 * @LastEditTime : 2020-10-23
 * @FilePath     : /tech_accumulation/杂项记录/问题记录/AUTPlayer扩展接口问题记录.md
 * @Description  : 
-->
# 更改接口之后无法播放
```shell
root@kunos:/root# ./autplayer 0 /qsws
WARNING: awplayer <log_set_level:30>: Set log level to 3
DEBUG  : awplayer <ReadPluginEntry:194>: read plugin entry adecoder-0 fail!
DEBUG  : awplayer <CdxPluginLoadList:221>: have config 0 entry
DEBUG  : awplayer <CdxPluginLoadList:222>: start to open adecoder lib
DEBUG  : awplayer <CdxPluginLoadList:202>: Load Plugin list vdecoder
DEBUG  : awplayer <ReadPluginEntry:178>: read plugin entry vdecoder-0 ok.
DEBUG  : awplayer <ReadPluginEntry:178>: read plugin entry vdecoder-1 ok.
DEBUG  : awplayer <ReadPluginEntry:178>: read plugin entry vdecoder-2 ok.
DEBUG  : awplayer <ReadPluginEntry:178>: read plugin entry vdecoder-3 ok.
DEBUG  : awplayer <ReadPluginEntry:178>: read plugin entry vdecoder-4 ok.
DEBUG  : awplayer <ReadPluginEntry:178>: read plugin entry vdecoder-5 ok.
DEBUG  : awplayer <ReadPluginEntry:178>: read plugin entry vdecoder-6 ok.
DEBUG  : awplayer <ReadPluginEntry:178>: read plugin entry vdecoder-7 ok.
DEBUG  : awplayer <ReadPluginEntry:178>: read plugin entry vdecoder-8 ok.
DEBUG  : awplayer <ReadPluginEntry:178>: read plugin entry vdecoder-9 ok.
DEBUG  : awplayer <ReadPluginEntry:178>: read plugin entry vdecoder-10 ok.
DEBUG  : awplayer <ReadPluginEntry:178>: read plugin entry vdecoder-11 ok.
DEBUG  : awplayer <ReadPluginEntry:178>: read plugin entry vdecoder-12 ok.
DEBUG  : awplayer <ReadPluginEntry:194>: read plugin entry vdecoder-13 fail!
DEBUG  : awplayer <CdxPluginLoadList:221>: have config 13 entry
DEBUG  : awplayer <CdxPluginLoadList:222>: start to open vdecoder lib
DEBUG  : awplayer <DlOpenPlugin:96>: plugin vdecoder.avs comment is "avs_vdecoder"
DEBUG  : awplayer <DlOpenPlugin:97>: plugin open lib: libawavs.so
DEBUG  : awplayer <DlOpenPlugin:116>: plugin init : CedarPluginVDInit
DEBUG  : awplayer <DlOpenPlugin:96>: plugin vdecoder.h264 comment is "h264_vdecoder"
DEBUG  : awplayer <DlOpenPlugin:97>: plugin open lib: libawh264.so
DEBUG  : awplayer <DlOpenPlugin:116>: plugin init : CedarPluginVDInit
DEBUG  : awplayer <DlOpenPlugin:96>: plugin vdecoder.h265 comment is "h265_vdecoder"
DEBUG  : awplayer <DlOpenPlugin:97>: plugin open lib: libawh265.so
DEBUG  : awplayer <DlOpenPlugin:116>: plugin init : CedarPluginVDInit
DEBUG  : awplayer <DlOpenPlugin:96>: plugin vdecoder.mjpeg comment is "mjpeg_vdecoder"
DEBUG  : awplayer <DlOpenPlugin:97>: plugin open lib: libawmjpeg.so
DEBUG  : awplayer <DlOpenPlugin:116>: plugin init : CedarPluginVDInit
DEBUG  : awplayer <DlOpenPlugin:96>: plugin vdecoder.mjpegplus comment is "mjpegplus_vdecoder"
DEBUG  : awplayer <DlOpenPlugin:97>: plugin open lib: libawmjpegplus.so
DEBUG  : awplayer <DlOpenPlugin:116>: plugin init : CedarPluginVDInit
DEBUG  : awplayer <DlOpenPlugin:96>: plugin vdecoder.mpeg2 comment is "mpeg2_vdecoder"
DEBUG  : awplayer <DlOpenPlugin:97>: plugin open lib: libawmpeg2.so
DEBUG  : awplayer <DlOpenPlugin:116>: plugin init : CedarPluginVDInit
DEBUG  : awplayer <DlOpenPlugin:96>: plugin vdecoder.mpeg4base comment is "mpeg4base_vdecoder"
DEBUG  : awplayer <DlOpenPlugin:97>: plugin open lib: libawmpeg4base.so
WARNING: awplayer <DlOpenPlugin:112>: Invalid plugin,function CedarPluginVDInit not found.
DEBUG  : awplayer <DlOpenPlugin:96>: plugin vdecoder.mpeg4dx comment is "mpeg4dx_vdecoder"
DEBUG  : awplayer <DlOpenPlugin:97>: plugin open lib: libawmpeg4dx.so
DEBUG  : awplayer <DlOpenPlugin:116>: plugin init : CedarPluginVDInit
DEBUG  : awplayer <DlOpenPlugin:96>: plugin vdecoder.mpeg4h263 comment is "mpeg4h263_vdecoder"
DEBUG  : awplayer <DlOpenPlugin:97>: plugin open lib: libawmpeg4h263.so
DEBUG  : awplayer <DlOpenPlugin:116>: plugin init : CedarPluginVDInit
DEBUG  : awplayer <DlOpenPlugin:96>: plugin vdecoder.mpeg4normal comment is "mpeg4normal_vdecoder"
DEBUG  : awplayer <DlOpenPlugin:97>: plugin open lib: libawmpeg4normal.so
DEBUG  : awplayer <DlOpenPlugin:116>: plugin init : CedarPluginVDInit
DEBUG  : awplayer <DlOpenPlugin:96>: plugin vdecoder.mpeg4vp6 comment is "mpeg4vp6_vdecoder"
DEBUG  : awplayer <DlOpenPlugin:97>: plugin open lib: libawmpeg4vp6.so
DEBUG  : awplayer <DlOpenPlugin:116>: plugin init : CedarPluginVDInit
DEBUG  : awplayer <DlOpenPlugin:96>: plugin vdecoder.vp8 comment is "vp8_vdecoder"
DEBUG  : awplayer <DlOpenPlugin:97>: plugin open lib: libawvp8.so
DEBUG  : awplayer <DlOpenPlugin:116>: plugin init : CedarPluginVDInit
DEBUG  : awplayer <DlOpenPlugin:96>: plugin vdecoder.wmv3 comment is "wmv3_vdecoder"
DEBUG  : awplayer <DlOpenPlugin:97>: plugin open lib: libawwmv3.so
DEBUG  : awplayer <DlOpenPlugin:116>: plugin init : CedarPluginVDInit
DEBUG  : awplayer <CdxPluginLoadList:202>: Load Plugin list plugin
DEBUG  : awplayer <ReadPluginEntry:194>: read plugin entry plugin-0 fail!
DEBUG  : awplayer <CdxPluginLoadList:221>: have config 0 entry
DEBUG  : awplayer <CdxPluginLoadList:222>: start to open plugin lib
DEBUG  : awplayer <AwStreamInit:92>: aw stream init...
DEBUG  : awplayer <AwStreamInit:124>: stream list size:6
INFO   : awplayer <AwParserInit:397>: aw parser init...
DEBUG  : awplayer <AwParserInit:467>: aw parser size:18
DEBUG  : awplayer <AwMuxerInit:53>: aw muxer init ..
DEBUG  : awplayer <AwMuxerInit:62>: aw muxer size:4
./autplayer: symbol lookup error: ./autplayer: undefined symbol: _ZN9AUTPlayerC1EP9SoundCtrlP9LayerCtrlP7SubCtrl
``` 

解决办法：将重新编译后的paly.so更新到平台

# 更新so后出现一直等待无法播放的情况
```shell
INFO   : demuxComponent <DemuxThread:3211>: waiting for stream buffer.
INFO   : demuxComponent <DemuxThread:3211>: waiting for stream buffer.
INFO   : demuxComponent <DemuxThread:3211>: waiting for stream buffer.
INFO   : demuxComponent <DemuxThread:3211>: waiting for stream buffer.
INFO   : demuxComponent <DemuxThread:3211>: waiting for stream buffer.
INFO   : demuxComponent <DemuxThread:3211>: waiting for stream buffer.
INFO   : demuxComponent <DemuxThread:3211>: waiting for stream buffer.
INFO   : demuxComponent <DemuxThread:3211>: waiting for stream buffer.
INFO   : demuxComponent <DemuxThread:3211>: waiting for stream buffer.
INFO   : demuxComponent <DemuxThread:3211>: waiting for stream buffer.
INFO   : demuxComponent <DemuxThread:3211>: waiting for stream buffer.
INFO   : demuxComponent <DemuxThread:3211>: waiting for stream buffer.
INFO   : demuxComponent <DemuxThread:3211>: waiting for stream buffer.
INFO   : demuxComponent <DemuxThread:3211>: waiting for stream buffer.
INFO   : demuxComponent <DemuxThread:3211>: waiting for stream buffer.
INFO   : demuxComponent <DemuxThread:3211>: waiting for stream buffer.
INFO   : demuxComponent <DemuxThread:3211>: waiting for stream buffer.
INFO   : demuxComponent <DemuxThread:3211>: waiting for stream buffer.
INFO   : demuxComponent <DemuxThread:3211>: waiting for stream buffer.
```

