/*
 * +AMDG
 */
/*
 * This document was begun on E July 1200, the Comm. of St.
 * Pius I, PM, and it is humbly dedicated to him and to the
 * Immaculate Heart of Mary for their prayers, and to the
 * Sacred Heart of Jesus for His mercy.
 *
 * dozcal:  keeps a calendar with a specific internal format
 * in dozenal
 *
 * (C) Copyright 2016  Donald P. Goodman III
 *
 * This file is part of dozcal.
 *
 * dozcal is free software:  you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any
 * later version.
 *
 * dozcal is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with dozcal.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<regex.h>
#include"conv.h"
#include"errcodes.h"
#include"event_struct.h"

#define MAX_ERR_LENGTH 256

extern double latitude;
extern double longitude;
extern double tzoffset;
extern int utc;
extern struct globopts *allopts;
extern int numopts;

int proc_options(char *s, int *moonphases, char **nat, char **relig,
					char **date_form, char **time_form, char **ev_form,
					char **todo_form, int *iftodo, int *ifevent,
					int *weekout, int *fdow, char **astro)
{
	FILE *fp; int holder; int implen;
	char *line = NULL; size_t len = 0; ssize_t read;
	int ind;

	if (strcmp(s,"-") == 0)
		return 0;
	if ((fp = fopen(s,"r")) == NULL) {
		fprintf(stderr,"dozcal:  unable to open file "
			"\"%s\", with this error:\n\t%d: "
			"%s\n",s,errno,strerror(errno));
		return 0;
	}
	while ((read = getline(&line, &len, fp)) != -1) {
		chomp(line);
		if (strstr(line,"MOON")) {
			if (strstr(line,"major"))
				*moonphases = 2;
			if (strstr(line,"all"))
				*moonphases = 1;
		} else if (strstr(line,"RELIG")) {
			holder = get_impstr(line);
			*relig = realloc(*relig,((strlen(line)+1) * sizeof(char)));
			strcpy(*relig,line+holder);
		} else if (strstr(line,"NATION")) {
			holder = get_impstr(line);
			*nat = realloc(*nat,((strlen(line)+1) * sizeof(char)));
			strcpy(*nat,line+holder);
		} else if (strstr(line,"ASTRON")) {
			holder = get_impstr(line);
			*astro = realloc(*astro,((strlen(line)+1) * sizeof(char)));
			strcpy(*astro,line+holder);
		} else if (strstr(line,"TIMEZONE")) {
			holder = get_impstr(line);
			tzoffset = doztodec(line+holder);
		} else if (strstr(line,"GEOG")) {
			holder = get_impstr(line);
			proc_geog(line+holder);
		} else if (strstr(line,"DATE_FORMAT")) {
			holder = get_impstr(line);
			*date_form = realloc(*date_form,((strlen(line)+1) * sizeof(char)));
			strcpy(*date_form,line+holder);
		} else if (strstr(line,"TIME_FORMAT")) {
			holder = get_impstr(line);
			*time_form = realloc(*time_form,((strlen(line)+1) * sizeof(char)));
			strcpy(*time_form,line+holder);
		} else if (strstr(line,"EVENT_FORMAT")) {
			holder = get_impstr(line);
			*ev_form = realloc(*ev_form,((strlen(line)+1) * sizeof(char)));
			strcpy(*ev_form,line+holder);
		} else if (strstr(line,"TODO_FORMAT")) {
			holder = get_impstr(line);
			*todo_form = realloc(*todo_form,((strlen(line)+1) * sizeof(char)));
			strcpy(*todo_form,line+holder);
		} else if (strstr(line,"INPUT")) {
			holder = get_impstr(line);
			process_file(line+holder);
		} else if (strstr(line,"SCRIPT")) {
			holder = get_impstr(line);
			call_lua(line+holder);
		} else if (strstr(line,"PRINT_TODOS")) {
			*iftodo = 1;
		} else if (strstr(line,"UTCTIME")) {
			utc = 1;
		} else if (strstr(line,"NO_EVENT")) {
			*ifevent = 0;
		} else if (strstr(line,"WEEKLY")) {
			*weekout = 1;
		} else if (strstr(line,"FIRST_DOW")) {
			holder = get_impstr(line);
			*fdow = first_dow(line+holder);
		} else if (strstr(line,"WHOLE_BG")) {
			ind = find_color_ind(line);
			holder = get_impstr(line);
			proc_color(line+holder,ind);
		}
/*	strcpy(allopts[NOCOLOR].opt,"NOCOLOR");
	strcpy(allopts[WHOLEBG].opt,"WHOLE_BG");
	strcpy(allopts[CALBG].opt,"CALENDAR_BG");
	strcpy(allopts[EVENTBG].opt,"EVENT_BG");
	strcpy(allopts[TODOBG].opt,"TODO_BG");
	strcpy(allopts[CALTITLEFORE].opt,"CAL_TITLE_FORE");
	strcpy(allopts[CALTITLEBACK].opt,"CAL_TITLE_BACK");
	strcpy(allopts[CALWEEKFORE].opt,"CAL_WEEK_FORE");
	strcpy(allopts[CALWEEKBACK].opt,"CAL_WEEK_BACK");
	strcpy(allopts[TODOTITLEFORE].opt,"TODO_TITLE_FORE");
	strcpy(allopts[TODOTITLEBACK].opt,"TODO_TITLE_BACK");
	strcpy(allopts[TODOLINEFORE].opt,"TODO_LINE_FORE");
	strcpy(allopts[TODOLINEBACK].opt,"TODO_LINE_BACK");
	strcpy(allopts[TODOFORE].opt,"TODO_FORE");
	strcpy(allopts[TODOBACK].opt,"TODO_BACK");
	strcpy(allopts[EVTITLEFORE].opt,"EV_TITLE_FORE");
	strcpy(allopts[EVTITLEBACK].opt,"EV_TITLE_BACK");
	strcpy(allopts[EVLINEFORE].opt,"EV_LINE_FORE");
	strcpy(allopts[EVLINEBACK].opt,"EV_LINE_BACK");
	strcpy(allopts[EVFORE].opt,"EV_FORE");
	strcpy(allopts[EVBACK].opt,"EV_BACK");
	strcpy(allopts[TITLEFORE].opt,"TITLE_FORE");
	strcpy(allopts[TITLEBACK].opt,"TITLE_BACK");
	strcpy(allopts[BOTFORE].opt,"BOT_FORE");
	strcpy(allopts[BOTBACK].opt,"BOT_BACK");
	strcpy(allopts[WARNINGFORE].opt,"WARNING_FORE");
	strcpy(allopts[WARNINGBACK].opt,"WARNING_BACK");
	strcpy(allopts[INACTIVEBORDFORE].opt,"INACTIVE_BORDER_FORE");
	strcpy(allopts[INACTIVEBORDBACK].opt,"INACTIVE_BORDER_BACK");
	strcpy(allopts[ACTIVEBORDFORE].opt,"ACTIVE_BORDER_FORE");
	strcpy(allopts[ACTIVEBORDBACK].opt,"ACTIVE_BORDER_BACK");
	strcpy(allopts[WHOLEEVBG].opt,"WHOLE_EV_BG");
	strcpy(allopts[WHOLETODOBG].opt,"WHOLE_TODO_BG");
	strcpy(allopts[CALFORE].opt,"CAL_FORE");
	strcpy(allopts[CALBACK].opt,"CAL_BACK");*/
	}
	free(line);
	fclose(fp);
	return 0;
}

int proc_color(char *s, int ind)
{
	int result; int errornum;
	int r, g, b;
	char holder[SHORTLEN];
	char err[MAX_ERR_LENGTH+1];
	regmatch_t pmatch[4]; size_t nmatch = 4;
	regex_t regone;
	char *colpat = 
		"\\([0-9XE][0-9XE]*\\),\\([0-9XE][0-9XE]*\\),\\([0-9XE][0-9XE]*\\)";

	holder[0] = '\0';
	lower_str(s);
	if (strstr(s,"red")) {
		allopts[ind].r = 1000; allopts[ind].g = 0; allopts[ind].b = 0;
	} else if (strstr(s,"blue")) {
		allopts[ind].r = 0; allopts[ind].g = 0; allopts[ind].b = 1000;
	} else if (strstr(s,"green")) {
		allopts[ind].r = 0; allopts[ind].g = 1000; allopts[ind].b = 0;
	} else if (strstr(s,"yellow")) {
		allopts[ind].r = 1000; allopts[ind].g = 1000; allopts[ind].b = 0;
	} else if (strstr(s,"magenta")) {
		allopts[ind].r = 1000; allopts[ind].g = 0; allopts[ind].b = 1000;
	} else if (strstr(s,"cyan")) {
		allopts[ind].r = 0; allopts[ind].g = 1000; allopts[ind].b = 1000;
	} else {
		if ((errornum = regcomp(&regone,colpat,0)) != 0) {
			regerror(errornum,&regone,err,MAX_ERR_LENGTH);
			return -1;
		}
		result = regexec(&regone,s,4,pmatch,0);
		regfree(&regone);
		if (result != 0) {		/* no match */
			if (strstr(s,"FORE")) {
				allopts[ind].r = 1000; allopts[ind].g = 1000;
				allopts[ind].b = 1000;
			} else {
				allopts[ind].r = 0; allopts[ind].g = 0;
				allopts[ind].b = 0;
			}
		} else {						/* match */
			sprintf(holder,"%.*s",pmatch[1].rm_eo - pmatch[1].rm_so, 
				s+pmatch[1].rm_so);
			allopts[ind].r = (int) doztodec(holder);
			holder[0] = '\0';
			sprintf(holder,"%.*s",pmatch[2].rm_eo - pmatch[2].rm_so, 
				s+pmatch[2].rm_so);
			allopts[ind].g = (int) doztodec(holder);
			holder[0] = '\0';
			sprintf(holder,"%.*s",pmatch[3].rm_eo - pmatch[3].rm_so, 
				s+pmatch[3].rm_so);
			allopts[ind].b = (int) doztodec(holder);
		}
	}
	return 0;
}

int find_color_ind(char *s)
{
	int i;
	int stop;
	char buffer[SHORTLEN];

	for (i = 0; s[i] != ':'; ++i)
		buffer[i] = s[i];
	buffer[i] = '\0';
	for (i = 0; i < numopts; ++i) {
		if (!strcmp(allopts[i].opt,buffer)) {
			return i;
		}
	}
	return -1;
}
