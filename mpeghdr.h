/*
 * mpeghdr.h:
 * MPEG audio header stuff.
 *
 * Copyright (c) 2002 Chris Lightfoot. All rights reserved.
 * Email: chris@ex-parrot.com; WWW: http://www.ex-parrot.com/~chris/
 *
 * $Id: mpeghdr.h,v 1.2 2002/06/01 11:44:17 chris Exp $
 *
 */

#ifndef __MPEGHDR_H_ /* include guard */
#define __MPEGHDR_H_

#include <stdbool.h>

#ifdef USE_SYS_INT_TYPES_H
#include <sys/int_types.h>  /* Solaris etc. */
#else
#include <stdint.h>         /* C99 standard. */
#endif

#include <stdio.h>

/* struct mpeg_audio_hdr:
 * Structure representing the four-byte header of an MPEG audio frame. */
struct mpeg_audio_hdr {
    enum { m_vers_unknown = 0, m_vers_1, m_vers_2, m_vers_2_5 } version;
    enum { m_layer_unknown = 0, m_layer_1, m_layer_2, m_layer_3 } layer;
    
    bool has_crc;
    uint16_t crc;

    int bitrate;
    int samplerate;
    
    bool padded;

    bool priv;
    
    enum { m_chan_stereo = 0, m_chan_joint, m_chan_dual, m_chan_mono} channels;

    uint8_t mode_extn;

    bool copyr, original;

    uint8_t emph;
};

/* mpeghdr.c */
int mpeg_hdr_parse(const uint8_t *data, struct mpeg_audio_hdr *h);
int mpeg_hdr_nextframe_offset(const struct mpeg_audio_hdr *h);
void mpeg_hdr_print(FILE *fp, const struct mpeg_audio_hdr *h);

#endif /* __MPEGHDR_H_ */
