# 表

|モード|プチコン4側のファイル名|ラズパイ側のファイル名|速度|説明|
|---|---|---|---|---|
|キーボード4bit|`RECVLIB_KEY4.PRG`|`send_key4.c`|約20bytes/sec|一回に4bitの情報を入れて通信します。1連続の抜けを検知できます。|
|パッド8bit|`RECVLIB_PAD8.PRG`|`send_pad8.c`|約48bytes/sec弱|一回に8bitの情報を入れて通信します。7連続までの抜けを検知できます。|
|パッド32bit|`RECVLIB_PAD32.PRG`|`send_pad32.c`|約192bytes/sec弱|一回に32bitの情報を入れて通信します。7連続までの抜けを検知できます。|