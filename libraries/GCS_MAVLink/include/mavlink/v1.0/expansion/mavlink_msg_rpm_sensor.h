// MESSAGE RPM_SENSOR PACKING

#define MAVLINK_MSG_ID_RPM_SENSOR 201

typedef struct __mavlink_rpm_sensor_t
{
 int16_t rpm; ///< rpm
} mavlink_rpm_sensor_t;

#define MAVLINK_MSG_ID_RPM_SENSOR_LEN 2
#define MAVLINK_MSG_ID_201_LEN 2

#define MAVLINK_MSG_ID_RPM_SENSOR_CRC 4
#define MAVLINK_MSG_ID_201_CRC 4



#define MAVLINK_MESSAGE_INFO_RPM_SENSOR { \
	"RPM_SENSOR", \
	1, \
	{  { "rpm", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_rpm_sensor_t, rpm) }, \
         } \
}


/**
 * @brief Pack a rpm_sensor message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param rpm rpm
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_rpm_sensor_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       int16_t rpm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_RPM_SENSOR_LEN];
	_mav_put_int16_t(buf, 0, rpm);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RPM_SENSOR_LEN);
#else
	mavlink_rpm_sensor_t packet;
	packet.rpm = rpm;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RPM_SENSOR_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_RPM_SENSOR;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RPM_SENSOR_LEN, MAVLINK_MSG_ID_RPM_SENSOR_CRC);
#else
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RPM_SENSOR_LEN);
#endif
}

/**
 * @brief Pack a rpm_sensor message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param rpm rpm
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_rpm_sensor_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           int16_t rpm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_RPM_SENSOR_LEN];
	_mav_put_int16_t(buf, 0, rpm);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RPM_SENSOR_LEN);
#else
	mavlink_rpm_sensor_t packet;
	packet.rpm = rpm;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RPM_SENSOR_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_RPM_SENSOR;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RPM_SENSOR_LEN, MAVLINK_MSG_ID_RPM_SENSOR_CRC);
#else
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RPM_SENSOR_LEN);
#endif
}

/**
 * @brief Encode a rpm_sensor struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param rpm_sensor C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_rpm_sensor_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_rpm_sensor_t* rpm_sensor)
{
	return mavlink_msg_rpm_sensor_pack(system_id, component_id, msg, rpm_sensor->rpm);
}

/**
 * @brief Encode a rpm_sensor struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param rpm_sensor C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_rpm_sensor_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_rpm_sensor_t* rpm_sensor)
{
	return mavlink_msg_rpm_sensor_pack_chan(system_id, component_id, chan, msg, rpm_sensor->rpm);
}

/**
 * @brief Send a rpm_sensor message
 * @param chan MAVLink channel to send the message
 *
 * @param rpm rpm
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_rpm_sensor_send(mavlink_channel_t chan, int16_t rpm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_RPM_SENSOR_LEN];
	_mav_put_int16_t(buf, 0, rpm);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RPM_SENSOR, buf, MAVLINK_MSG_ID_RPM_SENSOR_LEN, MAVLINK_MSG_ID_RPM_SENSOR_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RPM_SENSOR, buf, MAVLINK_MSG_ID_RPM_SENSOR_LEN);
#endif
#else
	mavlink_rpm_sensor_t packet;
	packet.rpm = rpm;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RPM_SENSOR, (const char *)&packet, MAVLINK_MSG_ID_RPM_SENSOR_LEN, MAVLINK_MSG_ID_RPM_SENSOR_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RPM_SENSOR, (const char *)&packet, MAVLINK_MSG_ID_RPM_SENSOR_LEN);
#endif
#endif
}

#if MAVLINK_MSG_ID_RPM_SENSOR_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_rpm_sensor_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int16_t rpm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_int16_t(buf, 0, rpm);

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RPM_SENSOR, buf, MAVLINK_MSG_ID_RPM_SENSOR_LEN, MAVLINK_MSG_ID_RPM_SENSOR_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RPM_SENSOR, buf, MAVLINK_MSG_ID_RPM_SENSOR_LEN);
#endif
#else
	mavlink_rpm_sensor_t *packet = (mavlink_rpm_sensor_t *)msgbuf;
	packet->rpm = rpm;

#if MAVLINK_CRC_EXTRA
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RPM_SENSOR, (const char *)packet, MAVLINK_MSG_ID_RPM_SENSOR_LEN, MAVLINK_MSG_ID_RPM_SENSOR_CRC);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RPM_SENSOR, (const char *)packet, MAVLINK_MSG_ID_RPM_SENSOR_LEN);
#endif
#endif
}
#endif

#endif

// MESSAGE RPM_SENSOR UNPACKING


/**
 * @brief Get field rpm from rpm_sensor message
 *
 * @return rpm
 */
static inline int16_t mavlink_msg_rpm_sensor_get_rpm(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Decode a rpm_sensor message into a struct
 *
 * @param msg The message to decode
 * @param rpm_sensor C-struct to decode the message contents into
 */
static inline void mavlink_msg_rpm_sensor_decode(const mavlink_message_t* msg, mavlink_rpm_sensor_t* rpm_sensor)
{
#if MAVLINK_NEED_BYTE_SWAP
	rpm_sensor->rpm = mavlink_msg_rpm_sensor_get_rpm(msg);
#else
	memcpy(rpm_sensor, _MAV_PAYLOAD(msg), MAVLINK_MSG_ID_RPM_SENSOR_LEN);
#endif
}
