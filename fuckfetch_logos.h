// These ASCII art logos taken from Neofetch. (MIT License - Dylan Araps)
// Bu ASCII art logolari NeoFetch'ten alinmistir. (MIT License - Dylan Araps)
// Kono ASCII aato rogo wa Neofetch kara shutoku saremashita. (MIT License - Dylan Araps)
// このASCIIアートロゴはNeofetchから取得されました。(MIT License - Dylan Araps)

#ifndef SLACKWARE_H
#define SLACKWARE_H

#include <stdio.h>

#define C1 "\033[1;34m"
#define C2 "\033[1;37m"
#define RESET "\033[0m"

static inline void print_slackware(void) {
    printf(
        C1 "                   :::::::\n"
        "             :::::::::::::::::::\n"
        "          :::::::::::::::::::::::::\n"
        "        ::::::::" C2 "cllcccccllllllll" C1 "::::::\n"
        "     :::::::::" C2 "lc               dc" C1 ":::::::\n"
        "    ::::::::" C2 "cl   clllccllll    oc" C1 ":::::::::\n"
        "   :::::::::" C2 "o   lc" C1 ":::::::::" C2 "co   oc" C1 "::::::::::\n"
        "  ::::::::::" C2 "o    cccclc" C1 ":::::" C2 "clcc" C1 "::::::::::::\n"
        "  :::::::::::" C2 "lc        cclccclc" C1 ":::::::::::::\n"
        " ::::::::::::::" C2 "lcclcc          lc" C1 "::::::::::::\n"
        " ::::::::::" C2 "cclcc" C1 ":::::" C2 "lccclc     oc" C1 ":::::::::::\n"
        " ::::::::::" C2 "o    l" C1 "::::::::::" C2 "l    lc" C1 ":::::::::::\n"
        "  :::::" C2 "cll" C1 ":" C2 "o     clcllcccll     o" C1 ":::::::::::\n"
        "  :::::" C2 "occ" C1 ":" C2 "o                  clc" C1 ":::::::::::\n"
        "   ::::" C2 "ocl" C1 ":" C2 "ccslclccclclccclclc" C1 ":::::::::::::\n"
        "    :::" C2 "oclcccccccccccccllllllllllllll" C1 ":::::\n"
        "     ::" C2 "lcc1lcccccccccccccccccccccccco" C1 "::::\n"
        "       ::::::::::::::::::::::::::::::::\n"
        "         ::::::::::::::::::::::::::::\n"
        "            ::::::::::::::::::::::\n"
        "                 ::::::::::::\n" RESET
    );
}

#endif
