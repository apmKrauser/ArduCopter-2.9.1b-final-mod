// agmatthews USERHOOKS

void userhook_init()
{
    // put your initialisation code her
	
	//memset(msg_toNano, 0, sizeof(msg_toNano));
	//memset(msg_fromNano, 0, sizeof(msg_fromNano));
	// baud, rx, tx
	Serial2.begin(38400, 10, 10);
	Serial2.set_blocking_writes(FALSE);

}

void userhook_50Hz()
{
    // put your 50Hz code here
	static uint8_t cnt = 0;
	cnt++;
	if ( (cnt == 1) || (cnt == (1 + 25)) ) read_from_Nano();
	if ( (cnt == 7) || (cnt == (7 + 25)) ) parse_from_Nano();
	if ( (cnt == 13) || (cnt == (13 + 25)) ) pack_msg_for_Nano();
	if ( (cnt == 19) || (cnt == (19 + 25)) ) write_to_Nano();
	if (cnt >= 50) {
		cnt = 0;
		loop_1Hz();
	}
}



void loop_1Hz()
{
	gcs0.send_message(MSG_RPM_SENSOR);
}

void parse_from_Nano() 
{
	byte ap_bitflags = 0;
	if (nanoRXi != msg_fromNano_size) return;
	nanoRXi = 0;
	if (msg_fromNano[0] != 0xFF) return;
	remote_RPM = (int32_t) ( msg_fromNano[1] + (msg_fromNano[2] << 8));
	ap_bitflags = msg_fromNano[3];
}

void read_from_Nano()
{
	int      c;
	while ((Serial2.available() > 0) && (nanoRXi < msg_fromNano_size))
	{
		c = Serial2.read();
		msg_fromNano[nanoRXi] = (byte) c;
		nanoRXi++;
	}
	while (Serial2.available() > 0) c = Serial2.read(); // clear buffer
}

void write_to_Nano()
{
	Serial2.write_buffer_nonblock(msg_toNano, msg_toNano_size);
}

void pack_msg_for_Nano()
{
	byte ap_bitflags = 0;
	uint16_t alt_by_sonar = 0;
	uint16_t alt_over_home = 0;
	if (ap.home_is_set) ap_bitflags |= 1 << 0;
    if (motors.armed() == true) ap_bitflags |= 1 << 1;
	alt_by_sonar = (uint16_t) sonar_alt;
	alt_over_home = (uint16_t) (( current_loc.alt - home.alt ) / 100);

	msg_toNano[0] = 0xFF;
	msg_toNano[1] = ap_bitflags;
	msg_toNano[2] = (byte) (alt_by_sonar & 0x00FF);
	msg_toNano[3] = (byte) ((alt_by_sonar & 0xFF00) >> 8);
	msg_toNano[4] = (byte) (alt_over_home & 0x00FF);
	msg_toNano[5] = (byte) ((alt_over_home & 0xFF00) >> 8);
}