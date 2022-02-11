#ifndef MYAUDIOINPUT_H
#define MYAUDIOINPUT_H

#include <QWidget>
#include "ui_myaudioinput.h"
#include <QFile>
#include <QAudioInput>
#include <QAudioOutput>

struct WAVFILEHEADER
{
    /// RIFF 头;
    char RiffName[4];          //资源交换文件标志，以RIFF标示
    unsigned long nRiffLength; //( 文件长度-8 )整个wav文件大小减去RIFFNAME和nRIFFLength所占用的字节数
    /// 数据类型标识符;
    char WavName[4]; //波形文件标识符，wav文件标志，表示是wav文件
    /// 格式块中的块头;
    char FmtName[4];          //（”fmt “）注意这里fmt后面还要加一个空格以满足4个字节,波形格式标志
    unsigned long nFmtLength; //表示格式块中块数据大小，通常为16，为18时表示格式块中块数据有附加信息
    /// 格式块中的块数据;
    unsigned short nAudioFormat;    //格式种类，也可以说是编码方式（值为1时，表示数据为线性PCM编码，大于1时表示有压缩的编码）
    unsigned short nChannleNumber;  //音频通道数目，1–单通道（声道）；2–双通道（声道）
    unsigned long nSampleRate;      //采样频率（每秒样本数）
    unsigned long nBytesPerSecond;  //波形数据传输速率（每秒平均字节数） （采样频率 × 音频通道数 × 每次采样得到的样本位数 / 8）
    unsigned short nBytesPerSample; //数据块对齐单位(每个采样需要的字节数) （通道数×每次采样得到的样本数据位值／8）
    unsigned short nBitsPerSample;  //每次采样得到的样本数据位数值（Qt助手中提到一般设置为8 或 16 ， 有一些系统可能支持更高的数据位数如24）
    /// 数据块中的块头;
    char DATANAME[4];          //（“data”） 数据块标识符
    unsigned long nDataLength; //采样数据总字节数 / 数据块中块数据总大小（即wav文件实际音频数据所占的大小）
};

class MyAudioInput : public QWidget
{
	Q_OBJECT

public:
	MyAudioInput(QWidget *parent = 0);
	~MyAudioInput();

private Q_SLOTS:
	void onStartRecord();
	void onStopRecording();
	void onPlay();
	void onStopPlay();
	qint64 addWavHeader(QString catheFileName, QString wavFileName);
	void handleStateChanged(QAudio::State state);
private:
	void timerEvent(QTimerEvent *event);

private:
	Ui::MyAudioInput ui;
	QFile destinationFile;
	QAudioInput* m_audioInput;
	QAudioOutput* m_audioOutput;
	QFile sourceFile;
	bool m_isRecord;
	bool m_isPlay;
	int m_RecordTimerId;
	int m_RecordTime;
};

#endif // MYAUDIOINPUT_H
