#ifndef MYAUDIOINPUT_H
#define MYAUDIOINPUT_H

#include <QWidget>
#include "ui_myaudioinput.h"
#include <QFile>
#include <QAudioInput>
#include <QAudioOutput>

struct WAVFILEHEADER
{
    /// RIFF ͷ;
    char RiffName[4];          //��Դ�����ļ���־����RIFF��ʾ
    unsigned long nRiffLength; //( �ļ�����-8 )����wav�ļ���С��ȥRIFFNAME��nRIFFLength��ռ�õ��ֽ���
    /// �������ͱ�ʶ��;
    char WavName[4]; //�����ļ���ʶ����wav�ļ���־����ʾ��wav�ļ�
    /// ��ʽ���еĿ�ͷ;
    char FmtName[4];          //����fmt ����ע������fmt���滹Ҫ��һ���ո�������4���ֽ�,���θ�ʽ��־
    unsigned long nFmtLength; //��ʾ��ʽ���п����ݴ�С��ͨ��Ϊ16��Ϊ18ʱ��ʾ��ʽ���п������и�����Ϣ
    /// ��ʽ���еĿ�����;
    unsigned short nAudioFormat;    //��ʽ���࣬Ҳ����˵�Ǳ��뷽ʽ��ֵΪ1ʱ����ʾ����Ϊ����PCM���룬����1ʱ��ʾ��ѹ���ı��룩
    unsigned short nChannleNumber;  //��Ƶͨ����Ŀ��1�C��ͨ������������2�C˫ͨ����������
    unsigned long nSampleRate;      //����Ƶ�ʣ�ÿ����������
    unsigned long nBytesPerSecond;  //�������ݴ������ʣ�ÿ��ƽ���ֽ����� ������Ƶ�� �� ��Ƶͨ���� �� ÿ�β����õ�������λ�� / 8��
    unsigned short nBytesPerSample; //���ݿ���뵥λ(ÿ��������Ҫ���ֽ���) ��ͨ������ÿ�β����õ�����������λֵ��8��
    unsigned short nBitsPerSample;  //ÿ�β����õ�����������λ��ֵ��Qt�������ᵽһ������Ϊ8 �� 16 �� ��һЩϵͳ����֧�ָ��ߵ�����λ����24��
    /// ���ݿ��еĿ�ͷ;
    char DATANAME[4];          //����data���� ���ݿ��ʶ��
    unsigned long nDataLength; //�����������ֽ��� / ���ݿ��п������ܴ�С����wav�ļ�ʵ����Ƶ������ռ�Ĵ�С��
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
