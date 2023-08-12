const Packet_t  = Uint8Array;
const Props_t   = Uint16Array;
const Command_t = Uint8Array;
type Packet_t = Uint8Array;
type Props_t   = Uint16Array;
type Command_t = Uint8Array;

export {
    Packet_t,
    Props_t,
    Command_t
};

export const Props = {
    NONE                                   : new Props_t([0x0000]),
    SUCCESS                                : new Props_t([0x0001]),
    FAIL                                   : new Props_t([0x0002]),
    SERVER_RESPONSE                        : new Props_t([0x0004]),
    CLIENT_RESPONSE                        : new Props_t([0x0008]),
    REQUEST_FOR_SERVER_RESPONSE            : new Props_t([0x0010]),
    REQUEST_FOR_NO_SERVER_RESPONSE         : new Props_t([0x0020]),
    REQUEST_FOR_NO_PREFERENCE_RESPONSE     : new Props_t([0x0000]),
    REQUEST_FOR_NOTIFY                     : new Props_t([0x0040]),
    REQUEST_FOR_NO_NOTIFY                  : new Props_t([0x0080]),
};

export const Command = {
    FLUSH                  : new Command_t([0x00]),
    WRITE                  : new Command_t([0x01]),
    SUBMIT                 : new Command_t([0x02]),
    CLEAR_WRITE            : new Command_t([0x03]),
    READ                   : new Command_t([0x04]),
    REC_BUFFER_SIZE        : new Command_t([0x05]),
    BYTES_LEFT             : new Command_t([0x06]),
    STRING                 : new Command_t([0x07]),
    PRINT_REC_BUFFER       : new Command_t([0x08]),
    STAGE_SMALL_BUFFER     : new Command_t([0x09]),
    PULL_SMALL_BUFFER      : new Command_t([0x0A]),
    SIZE_SMALL_BUFFER      : new Command_t([0x0B]),
    CLEAR_SMALL_BUFFER     : new Command_t([0x0C]),
    MTU_SETTING            : new Command_t([0x0D]),
    FILE_CREATE            : new Command_t([0x0E]),
    FILE_DELETE            : new Command_t([0x0F]),
    FILE_INFO              : new Command_t([0x10]),
    FILE_APPEND            : new Command_t([0x11]),
    PING            : new Command_t([0xFE]),
};
