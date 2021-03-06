#ifndef RTPSERVER_H
#define RTPSERVER_H

#include "video_streamer/VideoStreamer.h"

/**
 * UDP video server class
 */
namespace HighFlyers
{
class RtpServer : public VideoStreamer
{
private:

	/**< caps filter */
	GstElement* fmt;

	/**< video rate */
	GstElement* video_rate;

	/**< video convert */
	GstElement* video_convert;

	/**< rtp payloader */
	GstElement* payloader;

public:

	/**< Type of the video source */
	enum SourceType
	{
		//Uri, //TODO
		V4lDevice,
		VideoTest,
	};

	RtpServer();
	~RtpServer();

	/**
	 * \param source video source (e.g. /dev/video0 or file://fileName)
	 * \param type source type
	 *
	 * Set video to stream.
	 */
	void set_video_source( const std::string& source, SourceType type );

	/**
	 * \param host hostname or IP Address
	 *
	 * host used by server
	 */
	void set_ip( const std::string& host );

	/**
	 * \param caps caps, describing video (e.g. width, height, video format, framerate etc.)
	 *
	 * sets video caps
	 */
	void set_caps( const std::string& caps );
	/**
	* \param port Port
	*
	* Port
	*/
	void set_port( int port );

	/**
	*
	* \return true if initialization success
	*
	* initialization of stream that you have to use
	* after setting all necessary server parameters.
	*/
	bool init_stream();

	/**
	* Allows you to stop streaming
	*/
	void stop_stream();

	/**
	* Allows you to start streaming
	*/
	void start_stream();
};
}

#endif
