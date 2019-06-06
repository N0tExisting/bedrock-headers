#pragma once

#include "../NetworkIdentifier.h"
#include "../BinaryStream.h"
#include <string>

struct NetEventCallback;

/*
 * Important: When creating a subclass include PacketTemplate.h inside the class
 */
struct Packet {
	int unk_4 = 2, unk_8 = 1;
	unsigned char playerSubIndex = 0;

	Packet() = default;

	Packet(unsigned char playerSubIndex) : playerSubIndex(playerSubIndex) {}

	Packet(Packet const &packet) : unk_4(packet.unk_4), unk_8(packet.unk_8) {}

	// Change these in PacketTemplate.h as well

	virtual ~Packet() = 0 ;

	virtual int getId() const = 0;

	virtual std::string getName() const = 0;

	virtual void write(BinaryStream &) const = 0;

	virtual void read(BinaryStream &) = 0;

	virtual void handle(NetworkIdentifier const &, NetEventCallback &) const = 0;

	virtual bool disallowBatching() const = 0;

	// The stuff above is 13 bytes
};