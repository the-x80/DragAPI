#pragma once
#ifdef _WIN32
#include "../../../DragAPI.Core.h"
#include "../../../Event System/EventSystem.h"
#include "../../Window.h"

#include <functional>
#include <vector>

#include <Windows.h>

#include <d3d9.h>
#include <d3d10_1.h>
#include <d3d11.h>
#include <d3d12.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3d10_1.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3d12.lib")

const char* winmsg2str_impl(int id) {
#define F(A,B)case A:return #B;
    switch (id) {
        F(0, WM_NULL)
            F(1, WM_CREATE)
            F(2, WM_DESTROY)
            F(3, WM_MOVE)
            F(5, WM_SIZE)
            F(6, WM_ACTIVATE)
            F(7, WM_SETFOCUS)
            F(8, WM_KILLFOCUS)
            F(10, WM_ENABLE)
            F(11, WM_SETREDRAW)
            F(12, WM_SETTEXT)
            F(13, WM_GETTEXT)
            F(14, WM_GETTEXTLENGTH)
            F(15, WM_PAINT)
            F(16, WM_CLOSE)
            F(17, WM_QUERYENDSESSION)
            F(18, WM_QUIT)
            F(19, WM_QUERYOPEN)
            F(20, WM_ERASEBKGND)
            F(21, WM_SYSCOLORCHANGE)
            F(22, WM_ENDSESSION)
            F(24, WM_SHOWWINDOW)
            F(25, WM_CTLCOLOR)
            F(26, WM_WININICHANGE)
            F(27, WM_DEVMODECHANGE)
            F(28, WM_ACTIVATEAPP)
            F(29, WM_FONTCHANGE)
            F(30, WM_TIMECHANGE)
            F(31, WM_CANCELMODE)
            F(32, WM_SETCURSOR)
            F(33, WM_MOUSEACTIVATE)
            F(34, WM_CHILDACTIVATE)
            F(35, WM_QUEUESYNC)
            F(36, WM_GETMINMAXINFO)
            F(38, WM_PAINTICON)
            F(39, WM_ICONERASEBKGND)
            F(40, WM_NEXTDLGCTL)
            F(42, WM_SPOOLERSTATUS)
            F(43, WM_DRAWITEM)
            F(44, WM_MEASUREITEM)
            F(45, WM_DELETEITEM)
            F(46, WM_VKEYTOITEM)
            F(47, WM_CHARTOITEM)
            F(48, WM_SETFONT)
            F(49, WM_GETFONT)
            F(50, WM_SETHOTKEY)
            F(51, WM_GETHOTKEY)
            F(55, WM_QUERYDRAGICON)
            F(57, WM_COMPAREITEM)
            F(61, WM_GETOBJECT)
            F(65, WM_COMPACTING)
            F(68, WM_COMMNOTIFY)
            F(70, WM_WINDOWPOSCHANGING)
            F(71, WM_WINDOWPOSCHANGED)
            F(72, WM_POWER)
            F(73, WM_COPYGLOBALDATA)
            F(74, WM_COPYDATA)
            F(75, WM_CANCELJOURNAL)
            F(78, WM_NOTIFY)
            F(80, WM_INPUTLANGCHANGEREQUEST)
            F(81, WM_INPUTLANGCHANGE)
            F(82, WM_TCARD)
            F(83, WM_HELP)
            F(84, WM_USERCHANGED)
            F(85, WM_NOTIFYFORMAT)
            F(123, WM_CONTEXTMENU)
            F(124, WM_STYLECHANGING)
            F(125, WM_STYLECHANGED)
            F(126, WM_DISPLAYCHANGE)
            F(127, WM_GETICON)
            F(128, WM_SETICON)
            F(129, WM_NCCREATE)
            F(130, WM_NCDESTROY)
            F(131, WM_NCCALCSIZE)
            F(132, WM_NCHITTEST)
            F(133, WM_NCPAINT)
            F(134, WM_NCACTIVATE)
            F(135, WM_GETDLGCODE)
            F(136, WM_SYNCPAINT)
            F(160, WM_NCMOUSEMOVE)
            F(161, WM_NCLBUTTONDOWN)
            F(162, WM_NCLBUTTONUP)
            F(163, WM_NCLBUTTONDBLCLK)
            F(164, WM_NCRBUTTONDOWN)
            F(165, WM_NCRBUTTONUP)
            F(166, WM_NCRBUTTONDBLCLK)
            F(167, WM_NCMBUTTONDOWN)
            F(168, WM_NCMBUTTONUP)
            F(169, WM_NCMBUTTONDBLCLK)
            F(171, WM_NCXBUTTONDOWN)
            F(172, WM_NCXBUTTONUP)
            F(173, WM_NCXBUTTONDBLCLK)
            F(176, EM_GETSEL)
            F(177, EM_SETSEL)
            F(178, EM_GETRECT)
            F(179, EM_SETRECT)
            F(180, EM_SETRECTNP)
            F(181, EM_SCROLL)
            F(182, EM_LINESCROLL)
            F(183, EM_SCROLLCARET)
            F(185, EM_GETMODIFY)
            F(187, EM_SETMODIFY)
            F(188, EM_GETLINECOUNT)
            F(189, EM_LINEINDEX)
            F(190, EM_SETHANDLE)
            F(191, EM_GETHANDLE)
            F(192, EM_GETTHUMB)
            F(193, EM_LINELENGTH)
            F(194, EM_REPLACESEL)
            F(195, EM_SETFONT)
            F(196, EM_GETLINE)
            F(197, (EM_LIMITTEXT, EM_SETLIMITTEXT))
            F(198, EM_CANUNDO)
            F(199, EM_UNDO)
            F(200, EM_FMTLINES)
            F(201, EM_LINEFROMCHAR)
            F(202, EM_SETWORDBREAK)
            F(203, EM_SETTABSTOPS)
            F(204, EM_SETPASSWORDCHAR)
            F(205, EM_EMPTYUNDOBUFFER)
            F(206, EM_GETFIRSTVISIBLELINE)
            F(207, EM_SETREADONLY)
            F(209, (EM_SETWORDBREAKPROC, EM_GETWORDBREAKPROC))
            F(210, EM_GETPASSWORDCHAR)
            F(211, EM_SETMARGINS)
            F(212, EM_GETMARGINS)
            F(213, EM_GETLIMITTEXT)
            F(214, EM_POSFROMCHAR)
            F(215, EM_CHARFROMPOS)
            F(216, EM_SETIMESTATUS)
            F(217, EM_GETIMESTATUS)
            F(224, SBM_SETPOS)
            F(225, SBM_GETPOS)
            F(226, SBM_SETRANGE)
            F(227, SBM_GETRANGE)
            F(228, SBM_ENABLE_ARROWS)
            F(230, SBM_SETRANGEREDRAW)
            F(233, SBM_SETSCROLLINFO)
            F(234, SBM_GETSCROLLINFO)
            F(235, SBM_GETSCROLLBARINFO)
            F(240, BM_GETCHECK)
            F(241, BM_SETCHECK)
            F(242, BM_GETSTATE)
            F(243, BM_SETSTATE)
            F(244, BM_SETSTYLE)
            F(245, BM_CLICK)
            F(246, BM_GETIMAGE)
            F(247, BM_SETIMAGE)
            F(248, BM_SETDONTCLICK)
            F(255, WM_INPUT)
            F(256, WM_KEYDOWN)
            F(257, WM_KEYUP)
            F(258, WM_CHAR)
            F(259, WM_DEADCHAR)
            F(260, WM_SYSKEYDOWN)
            F(261, WM_SYSKEYUP)
            F(262, WM_SYSCHAR)
            F(263, WM_SYSDEADCHAR)
            F(265, (WM_UNICHAR, WM_WNT_CONVERTREQUESTEX))
            F(266, WM_CONVERTREQUEST)
            F(267, WM_CONVERTRESULT)
            F(268, WM_INTERIM)
            F(269, WM_IME_STARTCOMPOSITION)
            F(270, WM_IME_ENDCOMPOSITION)
            F(271, WM_IME_COMPOSITION)
            F(272, WM_INITDIALOG)
            F(273, WM_COMMAND)
            F(274, WM_SYSCOMMAND)
            F(275, WM_TIMER)
            F(276, WM_HSCROLL)
            F(277, WM_VSCROLL)
            F(278, WM_INITMENU)
            F(279, WM_INITMENUPOPUP)
            F(280, WM_SYSTIMER)
            F(287, WM_MENUSELECT)
            F(288, WM_MENUCHAR)
            F(289, WM_ENTERIDLE)
            F(290, WM_MENURBUTTONUP)
            F(291, WM_MENUDRAG)
            F(292, WM_MENUGETOBJECT)
            F(293, WM_UNINITMENUPOPUP)
            F(294, WM_MENUCOMMAND)
            F(295, WM_CHANGEUISTATE)
            F(296, WM_UPDATEUISTATE)
            F(297, WM_QUERYUISTATE)
            F(306, WM_CTLCOLORMSGBOX)
            F(307, WM_CTLCOLOREDIT)
            F(308, WM_CTLCOLORLISTBOX)
            F(309, WM_CTLCOLORBTN)
            F(310, WM_CTLCOLORDLG)
            F(311, WM_CTLCOLORSCROLLBAR)
            F(312, WM_CTLCOLORSTATIC)
            F(512, WM_MOUSEMOVE)
            F(513, WM_LBUTTONDOWN)
            F(514, WM_LBUTTONUP)
            F(515, WM_LBUTTONDBLCLK)
            F(516, WM_RBUTTONDOWN)
            F(517, WM_RBUTTONUP)
            F(518, WM_RBUTTONDBLCLK)
            F(519, WM_MBUTTONDOWN)
            F(520, WM_MBUTTONUP)
            F(521, WM_MBUTTONDBLCLK)
            F(522, WM_MOUSEWHEEL)
            F(523, WM_XBUTTONDOWN)
            F(524, WM_XBUTTONUP)
            F(525, WM_XBUTTONDBLCLK)
            F(526, WM_MOUSEHWHEEL)
            F(528, WM_PARENTNOTIFY)
            F(529, WM_ENTERMENULOOP)
            F(530, WM_EXITMENULOOP)
            F(531, WM_NEXTMENU)
            F(532, WM_SIZING)
            F(533, WM_CAPTURECHANGED)
            F(534, WM_MOVING)
            F(536, WM_POWERBROADCAST)
            F(537, WM_DEVICECHANGE)
            F(544, WM_MDICREATE)
            F(545, WM_MDIDESTROY)
            F(546, WM_MDIACTIVATE)
            F(547, WM_MDIRESTORE)
            F(548, WM_MDINEXT)
            F(549, WM_MDIMAXIMIZE)
            F(550, WM_MDITILE)
            F(551, WM_MDICASCADE)
            F(552, WM_MDIICONARRANGE)
            F(553, WM_MDIGETACTIVE)
            F(560, WM_MDISETMENU)
            F(561, WM_ENTERSIZEMOVE)
            F(562, WM_EXITSIZEMOVE)
            F(563, WM_DROPFILES)
            F(564, WM_MDIREFRESHMENU)
            F(640, WM_IME_REPORT)
            F(641, WM_IME_SETCONTEXT)
            F(642, WM_IME_NOTIFY)
            F(643, WM_IME_CONTROL)
            F(644, WM_IME_COMPOSITIONFULL)
            F(645, WM_IME_SELECT)
            F(646, WM_IME_CHAR)
            F(648, WM_IME_REQUEST)
            F(656, (WM_IMEKEYDOWN, WM_IME_KEYDOWN))
            F(657, (WM_IMEKEYUP, WM_IME_KEYUP))
            F(672, WM_NCMOUSEHOVER)
            F(673, WM_MOUSEHOVER)
            F(674, WM_NCMOUSELEAVE)
            F(675, WM_MOUSELEAVE)
            F(768, WM_CUT)
            F(769, WM_COPY)
            F(770, WM_PASTE)
            F(771, WM_CLEAR)
            F(772, WM_UNDO)
            F(773, WM_RENDERFORMAT)
            F(774, WM_RENDERALLFORMATS)
            F(775, WM_DESTROYCLIPBOARD)
            F(776, WM_DRAWCLIPBOARD)
            F(777, WM_PAINTCLIPBOARD)
            F(778, WM_VSCROLLCLIPBOARD)
            F(779, WM_SIZECLIPBOARD)
            F(780, WM_ASKCBFORMATNAME)
            F(781, WM_CHANGECBCHAIN)
            F(782, WM_HSCROLLCLIPBOARD)
            F(783, WM_QUERYNEWPALETTE)
            F(784, WM_PALETTEISCHANGING)
            F(785, WM_PALETTECHANGED)
            F(786, WM_HOTKEY)
            F(791, WM_PRINT)
            F(792, WM_PRINTCLIENT)
            F(793, WM_APPCOMMAND)
            F(856, WM_HANDHELDFIRST)
            F(863, WM_HANDHELDLAST)
            F(864, WM_AFXFIRST)
            F(895, WM_AFXLAST)
            F(896, WM_PENWINFIRST)
            F(897, WM_RCRESULT)
            F(898, WM_HOOKRCRESULT)
            F(899, (WM_GLOBALRCCHANGE, WM_PENMISCINFO))
            F(900, WM_SKB)
            F(901, (WM_HEDITCTL, WM_PENCTL))
            F(902, WM_PENMISC)
            F(903, WM_CTLINIT)
            F(904, WM_PENEVENT)
            F(911, WM_PENWINLAST)
            F(1024, (DDM_SETFMT, DM_GETDEFID, NIN_SELECT, TBM_GETPOS, WM_PSD_PAGESETUPDLG, WM_USER))
            F(1025, (CBEM_INSERTITEMA, DDM_DRAW, DM_SETDEFID, HKM_SETHOTKEY, PBM_SETRANGE, RB_INSERTBANDA, SB_SETTEXTA, TB_ENABLEBUTTON, TBM_GETRANGEMIN, TTM_ACTIVATE, WM_CHOOSEFONT_GETLOGFONT, WM_PSD_FULLPAGERECT))
            F(1026, (CBEM_SETIMAGELIST, DDM_CLOSE, DM_REPOSITION, HKM_GETHOTKEY, PBM_SETPOS, RB_DELETEBAND, SB_GETTEXTA, TB_CHECKBUTTON, TBM_GETRANGEMAX, WM_PSD_MINMARGINRECT))
            F(1027, (CBEM_GETIMAGELIST, DDM_BEGIN, HKM_SETRULES, PBM_DELTAPOS, RB_GETBARINFO, SB_GETTEXTLENGTHA, TBM_GETTIC, TB_PRESSBUTTON, TTM_SETDELAYTIME, WM_PSD_MARGINRECT))
            F(1028, (CBEM_GETITEMA, DDM_END, PBM_SETSTEP, RB_SETBARINFO, SB_SETPARTS, TB_HIDEBUTTON, TBM_SETTIC, TTM_ADDTOOLA, WM_PSD_GREEKTEXTRECT))
            F(1029, (CBEM_SETITEMA, PBM_STEPIT, TB_INDETERMINATE, TBM_SETPOS, TTM_DELTOOLA, WM_PSD_ENVSTAMPRECT))
            F(1030, (CBEM_GETCOMBOCONTROL, PBM_SETRANGE32, RB_SETBANDINFOA, SB_GETPARTS, TB_MARKBUTTON, TBM_SETRANGE, TTM_NEWTOOLRECTA, WM_PSD_YAFULLPAGERECT))
            F(1031, (CBEM_GETEDITCONTROL, PBM_GETRANGE, RB_SETPARENT, SB_GETBORDERS, TBM_SETRANGEMIN, TTM_RELAYEVENT))
            F(1032, (CBEM_SETEXSTYLE, PBM_GETPOS, RB_HITTEST, SB_SETMINHEIGHT, TBM_SETRANGEMAX, TTM_GETTOOLINFOA))
            F(1033, (CBEM_GETEXSTYLE, CBEM_GETEXTENDEDSTYLE, PBM_SETBARCOLOR, RB_GETRECT, SB_SIMPLE, TB_ISBUTTONENABLED, TBM_CLEARTICS, TTM_SETTOOLINFOA))
            F(1034, (CBEM_HASEDITCHANGED, RB_INSERTBANDW, SB_GETRECT, TB_ISBUTTONCHECKED, TBM_SETSEL, TTM_HITTESTA, WIZ_QUERYNUMPAGES))
            F(1035, (CBEM_INSERTITEMW, RB_SETBANDINFOW, SB_SETTEXTW, TB_ISBUTTONPRESSED, TBM_SETSELSTART, TTM_GETTEXTA, WIZ_NEXT))
            F(1036, (CBEM_SETITEMW, RB_GETBANDCOUNT, SB_GETTEXTLENGTHW, TB_ISBUTTONHIDDEN, TBM_SETSELEND, TTM_UPDATETIPTEXTA, WIZ_PREV))
            F(1037, (CBEM_GETITEMW, RB_GETROWCOUNT, SB_GETTEXTW, TB_ISBUTTONINDETERMINATE, TTM_GETTOOLCOUNT))
            F(1038, (CBEM_SETEXTENDEDSTYLE, RB_GETROWHEIGHT, SB_ISSIMPLE, TB_ISBUTTONHIGHLIGHTED, TBM_GETPTICS, TTM_ENUMTOOLSA))
            F(1039, (SB_SETICON, TBM_GETTICPOS, TTM_GETCURRENTTOOLA))
            F(1040, (RB_IDTOINDEX, SB_SETTIPTEXTA, TBM_GETNUMTICS, TTM_WINDOWFROMPOINT))
            F(1041, (RB_GETTOOLTIPS, SB_SETTIPTEXTW, TBM_GETSELSTART, TB_SETSTATE, TTM_TRACKACTIVATE))
            F(1042, (RB_SETTOOLTIPS, SB_GETTIPTEXTA, TB_GETSTATE, TBM_GETSELEND, TTM_TRACKPOSITION))
            F(1043, (RB_SETBKCOLOR, SB_GETTIPTEXTW, TB_ADDBITMAP, TBM_CLEARSEL, TTM_SETTIPBKCOLOR))
            F(1044, (RB_GETBKCOLOR, SB_GETICON, TB_ADDBUTTONSA, TBM_SETTICFREQ, TTM_SETTIPTEXTCOLOR))
            F(1045, (RB_SETTEXTCOLOR, TB_INSERTBUTTONA, TBM_SETPAGESIZE, TTM_GETDELAYTIME))
            F(1046, (RB_GETTEXTCOLOR, TB_DELETEBUTTON, TBM_GETPAGESIZE, TTM_GETTIPBKCOLOR))
            F(1047, (RB_SIZETORECT, TB_GETBUTTON, TBM_SETLINESIZE, TTM_GETTIPTEXTCOLOR))
            F(1048, (RB_BEGINDRAG, TB_BUTTONCOUNT, TBM_GETLINESIZE, TTM_SETMAXTIPWIDTH))
            F(1049, (RB_ENDDRAG, TB_COMMANDTOINDEX, TBM_GETTHUMBRECT, TTM_GETMAXTIPWIDTH))
            F(1050, (RB_DRAGMOVE, TBM_GETCHANNELRECT, TB_SAVERESTOREA, TTM_SETMARGIN))
            F(1051, (RB_GETBARHEIGHT, TB_CUSTOMIZE, TBM_SETTHUMBLENGTH, TTM_GETMARGIN))
            F(1052, (RB_GETBANDINFOW, TB_ADDSTRINGA, TBM_GETTHUMBLENGTH, TTM_POP))
            F(1053, (RB_GETBANDINFOA, TB_GETITEMRECT, TBM_SETTOOLTIPS, TTM_UPDATE))
            F(1054, (RB_MINIMIZEBAND, TB_BUTTONSTRUCTSIZE, TBM_GETTOOLTIPS, TTM_GETBUBBLESIZE))
            F(1055, (RB_MAXIMIZEBAND, TBM_SETTIPSIDE, TB_SETBUTTONSIZE, TTM_ADJUSTRECT))
            F(1056, (TBM_SETBUDDY, TB_SETBITMAPSIZE, TTM_SETTITLEA))
            F(1057, (MSG_FTS_JUMP_VA, TB_AUTOSIZE, TBM_GETBUDDY, TTM_SETTITLEW))
            F(1058, RB_GETBANDBORDERS)
            F(1059, (MSG_FTS_JUMP_QWORD, RB_SHOWBAND, TB_GETTOOLTIPS))
            F(1060, (MSG_REINDEX_REQUEST, TB_SETTOOLTIPS))
            F(1061, (MSG_FTS_WHERE_IS_IT, RB_SETPALETTE, TB_SETPARENT))
            F(1062, RB_GETPALETTE)
            F(1063, (RB_MOVEBAND, TB_SETROWS))
            F(1064, TB_GETROWS)
            F(1065, TB_GETBITMAPFLAGS)
            F(1066, TB_SETCMDID)
            F(1067, (RB_PUSHCHEVRON, TB_CHANGEBITMAP))
            F(1068, TB_GETBITMAP)
            F(1069, (MSG_GET_DEFFONT, TB_GETBUTTONTEXTA))
            F(1070, TB_REPLACEBITMAP)
            F(1071, TB_SETINDENT)
            F(1072, TB_SETIMAGELIST)
            F(1073, TB_GETIMAGELIST)
            F(1074, (TB_LOADIMAGES, EM_CANPASTE, TTM_ADDTOOLW))
            F(1075, (EM_DISPLAYBAND, TB_GETRECT, TTM_DELTOOLW))
            F(1076, (EM_EXGETSEL, TB_SETHOTIMAGELIST, TTM_NEWTOOLRECTW))
            F(1077, (EM_EXLIMITTEXT, TB_GETHOTIMAGELIST, TTM_GETTOOLINFOW))
            F(1078, (EM_EXLINEFROMCHAR, TB_SETDISABLEDIMAGELIST, TTM_SETTOOLINFOW))
            F(1079, (EM_EXSETSEL, TB_GETDISABLEDIMAGELIST, TTM_HITTESTW))
            F(1080, (EM_FINDTEXT, TB_SETSTYLE, TTM_GETTEXTW))
            F(1081, (EM_FORMATRANGE, TB_GETSTYLE, TTM_UPDATETIPTEXTW))
            F(1082, (EM_GETCHARFORMAT, TB_GETBUTTONSIZE, TTM_ENUMTOOLSW))
            F(1083, (EM_GETEVENTMASK, TB_SETBUTTONWIDTH, TTM_GETCURRENTTOOLW))
            F(1084, (EM_GETOLEINTERFACE, TB_SETMAXTEXTROWS))
            F(1085, (EM_GETPARAFORMAT, TB_GETTEXTROWS))
            F(1086, (EM_GETSELTEXT, TB_GETOBJECT))
            F(1087, (EM_HIDESELECTION, TB_GETBUTTONINFOW))
            F(1088, (EM_PASTESPECIAL, TB_SETBUTTONINFOW))
            F(1089, (EM_REQUESTRESIZE, TB_GETBUTTONINFOA))
            F(1090, (EM_SELECTIONTYPE, TB_SETBUTTONINFOA))
            F(1091, (EM_SETBKGNDCOLOR, TB_INSERTBUTTONW))
            F(1092, (EM_SETCHARFORMAT, TB_ADDBUTTONSW))
            F(1093, (EM_SETEVENTMASK, TB_HITTEST))
            F(1094, (EM_SETOLECALLBACK, TB_SETDRAWTEXTFLAGS))
            F(1095, (EM_SETPARAFORMAT, TB_GETHOTITEM))
            F(1096, (EM_SETTARGETDEVICE, TB_SETHOTITEM))
            F(1097, (EM_STREAMIN, TB_SETANCHORHIGHLIGHT))
            F(1098, (EM_STREAMOUT, TB_GETANCHORHIGHLIGHT))
            F(1099, (EM_GETTEXTRANGE, TB_GETBUTTONTEXTW))
            F(1100, (EM_FINDWORDBREAK, TB_SAVERESTOREW))
            F(1101, (EM_SETOPTIONS, TB_ADDSTRINGW))
            F(1102, (EM_GETOPTIONS, TB_MAPACCELERATORA))
            F(1103, (EM_FINDTEXTEX, TB_GETINSERTMARK))
            F(1104, (EM_GETWORDBREAKPROCEX, TB_SETINSERTMARK))
            F(1105, (EM_SETWORDBREAKPROCEX, TB_INSERTMARKHITTEST))
            F(1106, (EM_SETUNDOLIMIT, TB_MOVEBUTTON))
            F(1107, TB_GETMAXSIZE)
            F(1108, (EM_REDO, TB_SETEXTENDEDSTYLE))
            F(1109, (EM_CANREDO, TB_GETEXTENDEDSTYLE))
            F(1110, (EM_GETUNDONAME, TB_GETPADDING))
            F(1111, (EM_GETREDONAME, TB_SETPADDING))
            F(1112, (EM_STOPGROUPTYPING, TB_SETINSERTMARKCOLOR))
            F(1113, (EM_SETTEXTMODE, TB_GETINSERTMARKCOLOR))
            F(1114, (EM_GETTEXTMODE, TB_MAPACCELERATORW))
            F(1115, (EM_AUTOURLDETECT, TB_GETSTRINGW))
            F(1116, (EM_GETAUTOURLDETECT, TB_GETSTRINGA))
            F(1117, EM_SETPALETTE)
            F(1118, EM_GETTEXTEX)
            F(1119, EM_GETTEXTLENGTHEX)
            F(1120, EM_SHOWSCROLLBAR)
            F(1121, EM_SETTEXTEX)
            F(1123, TAPI_REPLY)
            F(1124, (ACM_OPENA, BFFM_SETSTATUSTEXTA, CDM_GETSPEC, EM_SETPUNCTUATION, IPM_CLEARADDRESS, WM_CAP_UNICODE_START))
            F(1125, (ACM_PLAY, BFFM_ENABLEOK, CDM_GETFILEPATH, EM_GETPUNCTUATION, IPM_SETADDRESS, PSM_SETCURSEL, UDM_SETRANGE, WM_CHOOSEFONT_SETLOGFONT))
            F(1126, (ACM_STOP, BFFM_SETSELECTIONA, CDM_GETFOLDERPATH, EM_SETWORDWRAPMODE, IPM_GETADDRESS, PSM_REMOVEPAGE, UDM_GETRANGE, WM_CAP_SET_CALLBACK_ERRORW, WM_CHOOSEFONT_SETFLAGS))
            F(1127, (ACM_OPENW, BFFM_SETSELECTIONW, CDM_GETFOLDERIDLIST, EM_GETWORDWRAPMODE, IPM_SETRANGE, PSM_ADDPAGE, UDM_SETPOS, WM_CAP_SET_CALLBACK_STATUSW))
            F(1128, (BFFM_SETSTATUSTEXTW, CDM_SETCONTROLTEXT, EM_SETIMECOLOR, IPM_SETFOCUS, PSM_CHANGED, UDM_GETPOS))
            F(1129, (CDM_HIDECONTROL, EM_GETIMECOLOR, IPM_ISBLANK, PSM_RESTARTWINDOWS, UDM_SETBUDDY))
            F(1130, (CDM_SETDEFEXT, EM_SETIMEOPTIONS, PSM_REBOOTSYSTEM, UDM_GETBUDDY))
            F(1131, (EM_GETIMEOPTIONS, PSM_CANCELTOCLOSE, UDM_SETACCEL))
            F(1132, (EM_CONVPOSITION, EM_CONVPOSITION, PSM_QUERYSIBLINGS, UDM_GETACCEL))
            F(1133, (MCIWNDM_GETZOOM, PSM_UNCHANGED, UDM_SETBASE))
            F(1134, (PSM_APPLY, UDM_GETBASE))
            F(1135, (PSM_SETTITLEA, UDM_SETRANGE32))
            F(1136, (PSM_SETWIZBUTTONS, UDM_GETRANGE32, WM_CAP_DRIVER_GET_NAMEW))
            F(1137, (PSM_PRESSBUTTON, UDM_SETPOS32, WM_CAP_DRIVER_GET_VERSIONW))
            F(1138, (PSM_SETCURSELID, UDM_GETPOS32))
            F(1139, PSM_SETFINISHTEXTA)
            F(1140, PSM_GETTABCONTROL)
            F(1141, PSM_ISDIALOGMESSAGE)
            F(1142, (MCIWNDM_REALIZE, PSM_GETCURRENTPAGEHWND))
            F(1143, (MCIWNDM_SETTIMEFORMATA, PSM_INSERTPAGE))
            F(1144, (EM_SETLANGOPTIONS, MCIWNDM_GETTIMEFORMATA, PSM_SETTITLEW, WM_CAP_FILE_SET_CAPTURE_FILEW))
            F(1145, (EM_GETLANGOPTIONS, MCIWNDM_VALIDATEMEDIA, PSM_SETFINISHTEXTW, WM_CAP_FILE_GET_CAPTURE_FILEW))
            F(1146, EM_GETIMECOMPMODE)
            F(1147, (EM_FINDTEXTW, MCIWNDM_PLAYTO, WM_CAP_FILE_SAVEASW))
            F(1148, (EM_FINDTEXTEXW, MCIWNDM_GETFILENAMEA))
            F(1149, (EM_RECONVERSION, MCIWNDM_GETDEVICEA, PSM_SETHEADERTITLEA, WM_CAP_FILE_SAVEDIBW))
            F(1150, (EM_SETIMEMODEBIAS, MCIWNDM_GETPALETTE, PSM_SETHEADERTITLEW))
            F(1151, (EM_GETIMEMODEBIAS, MCIWNDM_SETPALETTE, PSM_SETHEADERSUBTITLEA))
            F(1152, (MCIWNDM_GETERRORA, PSM_SETHEADERSUBTITLEW))
            F(1153, PSM_HWNDTOINDEX)
            F(1154, PSM_INDEXTOHWND)
            F(1155, (MCIWNDM_SETINACTIVETIMER, PSM_PAGETOINDEX))
            F(1156, PSM_INDEXTOPAGE)
            F(1157, (DL_BEGINDRAG, MCIWNDM_GETINACTIVETIMER, PSM_IDTOINDEX))
            F(1158, (DL_DRAGGING, PSM_INDEXTOID))
            F(1159, (DL_DROPPED, PSM_GETRESULT))
            F(1160, (DL_CANCELDRAG, PSM_RECALCPAGESIZES))
            F(1164, MCIWNDM_GET_SOURCE)
            F(1165, MCIWNDM_PUT_SOURCE)
            F(1166, MCIWNDM_GET_DEST)
            F(1167, MCIWNDM_PUT_DEST)
            F(1168, MCIWNDM_CAN_PLAY)
            F(1169, MCIWNDM_CAN_WINDOW)
            F(1170, MCIWNDM_CAN_RECORD)
            F(1171, MCIWNDM_CAN_SAVE)
            F(1172, MCIWNDM_CAN_EJECT)
            F(1173, MCIWNDM_CAN_CONFIG)
            F(1174, (IE_GETINK, MCIWNDM_PALETTEKICK))
            F(1175, IE_SETINK)
            F(1176, IE_GETPENTIP)
            F(1177, IE_SETPENTIP)
            F(1178, IE_GETERASERTIP)
            F(1179, IE_SETERASERTIP)
            F(1180, IE_GETBKGND)
            F(1181, IE_SETBKGND)
            F(1182, IE_GETGRIDORIGIN)
            F(1183, IE_SETGRIDORIGIN)
            F(1184, IE_GETGRIDPEN)
            F(1185, IE_SETGRIDPEN)
            F(1186, IE_GETGRIDSIZE)
            F(1187, IE_SETGRIDSIZE)
            F(1188, IE_GETMODE)
            F(1189, IE_SETMODE)
            F(1190, (IE_GETINKRECT, WM_CAP_SET_MCI_DEVICEW))
            F(1191, WM_CAP_GET_MCI_DEVICEW)
            F(1204, WM_CAP_PAL_OPENW)
            F(1205, WM_CAP_PAL_SAVEW)
            F(1208, IE_GETAPPDATA)
            F(1209, IE_SETAPPDATA)
            F(1210, IE_GETDRAWOPTS)
            F(1211, IE_SETDRAWOPTS)
            F(1212, IE_GETFORMAT)
            F(1213, IE_SETFORMAT)
            F(1214, IE_GETINKINPUT)
            F(1215, IE_SETINKINPUT)
            F(1216, IE_GETNOTIFY)
            F(1217, IE_SETNOTIFY)
            F(1218, IE_GETRECOG)
            F(1219, IE_SETRECOG)
            F(1220, IE_GETSECURITY)
            F(1221, IE_SETSECURITY)
            F(1222, IE_GETSEL)
            F(1223, IE_SETSEL)
            F(1224, (EM_SETBIDIOPTIONS, IE_DOCOMMAND, MCIWNDM_NOTIFYMODE))
            F(1225, (EM_GETBIDIOPTIONS, IE_GETCOMMAND))
            F(1226, (EM_SETTYPOGRAPHYOPTIONS, IE_GETCOUNT))
            F(1227, (EM_GETTYPOGRAPHYOPTIONS, IE_GETGESTURE, MCIWNDM_NOTIFYMEDIA))
            F(1228, (EM_SETEDITSTYLE, IE_GETMENU))
            F(1229, (EM_GETEDITSTYLE, IE_GETPAINTDC, MCIWNDM_NOTIFYERROR))
            F(1230, IE_GETPDEVENT)
            F(1231, IE_GETSELCOUNT)
            F(1232, IE_GETSELITEMS)
            F(1233, IE_GETSTYLE)
            F(1243, MCIWNDM_SETTIMEFORMATW)
            F(1244, (EM_OUTLINE, MCIWNDM_GETTIMEFORMATW))
            F(1245, EM_GETSCROLLPOS)
            F(1246, (EM_SETSCROLLPOS, EM_SETSCROLLPOS))
            F(1247, EM_SETFONTSIZE)
            F(1248, (EM_GETZOOM, MCIWNDM_GETFILENAMEW))
            F(1249, (EM_SETZOOM, MCIWNDM_GETDEVICEW))
            F(1250, EM_GETVIEWKIND)
            F(1251, EM_SETVIEWKIND)
            F(1252, (EM_GETPAGE, MCIWNDM_GETERRORW))
            F(1253, EM_SETPAGE)
            F(1254, EM_GETHYPHENATEINFO)
            F(1255, EM_SETHYPHENATEINFO)
            F(1259, EM_GETPAGEROTATE)
            F(1260, EM_SETPAGEROTATE)
            F(1261, EM_GETCTFMODEBIAS)
            F(1262, EM_SETCTFMODEBIAS)
            F(1264, EM_GETCTFOPENSTATUS)
            F(1265, EM_SETCTFOPENSTATUS)
            F(1266, EM_GETIMECOMPTEXT)
            F(1267, EM_ISIME)
            F(1268, EM_GETIMEPROPERTY)
            F(1293, EM_GETQUERYRTFOBJ)
            F(1294, EM_SETQUERYRTFOBJ)
            F(1536, FM_GETFOCUS)
            F(1537, FM_GETDRIVEINFOA)
            F(1538, FM_GETSELCOUNT)
            F(1539, FM_GETSELCOUNTLFN)
            F(1540, FM_GETFILESELA)
            F(1541, FM_GETFILESELLFNA)
            F(1542, FM_REFRESH_WINDOWS)
            F(1543, FM_RELOAD_EXTENSIONS)
            F(1553, FM_GETDRIVEINFOW)
            F(1556, FM_GETFILESELW)
            F(1557, FM_GETFILESELLFNW)
            F(1625, WLX_WM_SAS)
            F(2024, (SM_GETSELCOUNT, UM_GETSELCOUNT, WM_CPL_LAUNCH))
            F(2025, (SM_GETSERVERSELA, UM_GETUSERSELA, WM_CPL_LAUNCHED))
            F(2026, (SM_GETSERVERSELW, UM_GETUSERSELW))
            F(2027, (SM_GETCURFOCUSA, UM_GETGROUPSELA))
            F(2028, (SM_GETCURFOCUSW, UM_GETGROUPSELW))
            F(2029, (SM_GETOPTIONS, UM_GETCURFOCUSA))
            F(2030, UM_GETCURFOCUSW)
            F(2031, UM_GETOPTIONS)
            F(2032, UM_GETOPTIONS2)
            F(4096, LVM_GETBKCOLOR)
            F(4097, LVM_SETBKCOLOR)
            F(4098, LVM_GETIMAGELIST)
            F(4099, LVM_SETIMAGELIST)
            F(4100, LVM_GETITEMCOUNT)
            F(4101, LVM_GETITEMA)
            F(4102, LVM_SETITEMA)
            F(4103, LVM_INSERTITEMA)
            F(4104, LVM_DELETEITEM)
            F(4105, LVM_DELETEALLITEMS)
            F(4106, LVM_GETCALLBACKMASK)
            F(4107, LVM_SETCALLBACKMASK)
            F(4108, LVM_GETNEXTITEM)
            F(4109, LVM_FINDITEMA)
            F(4110, LVM_GETITEMRECT)
            F(4111, LVM_SETITEMPOSITION)
            F(4112, LVM_GETITEMPOSITION)
            F(4113, LVM_GETSTRINGWIDTHA)
            F(4114, LVM_HITTEST)
            F(4115, LVM_ENSUREVISIBLE)
            F(4116, LVM_SCROLL)
            F(4117, LVM_REDRAWITEMS)
            F(4118, LVM_ARRANGE)
            F(4119, LVM_EDITLABELA)
            F(4120, LVM_GETEDITCONTROL)
            F(4121, LVM_GETCOLUMNA)
            F(4122, LVM_SETCOLUMNA)
            F(4123, LVM_INSERTCOLUMNA)
            F(4124, LVM_DELETECOLUMN)
            F(4125, LVM_GETCOLUMNWIDTH)
            F(4126, LVM_SETCOLUMNWIDTH)
            F(4127, LVM_GETHEADER)
            F(4129, LVM_CREATEDRAGIMAGE)
            F(4130, LVM_GETVIEWRECT)
            F(4131, LVM_GETTEXTCOLOR)
            F(4132, LVM_SETTEXTCOLOR)
            F(4133, LVM_GETTEXTBKCOLOR)
            F(4134, LVM_SETTEXTBKCOLOR)
            F(4135, LVM_GETTOPINDEX)
            F(4136, LVM_GETCOUNTPERPAGE)
            F(4137, LVM_GETORIGIN)
            F(4138, LVM_UPDATE)
            F(4139, LVM_SETITEMSTATE)
            F(4140, LVM_GETITEMSTATE)
            F(4141, LVM_GETITEMTEXTA)
            F(4142, LVM_SETITEMTEXTA)
            F(4143, LVM_SETITEMCOUNT)
            F(4144, LVM_SORTITEMS)
            F(4145, LVM_SETITEMPOSITION32)
            F(4146, LVM_GETSELECTEDCOUNT)
            F(4147, LVM_GETITEMSPACING)
            F(4148, LVM_GETISEARCHSTRINGA)
            F(4149, LVM_SETICONSPACING)
            F(4150, LVM_SETEXTENDEDLISTVIEWSTYLE)
            F(4151, LVM_GETEXTENDEDLISTVIEWSTYLE)
            F(4152, LVM_GETSUBITEMRECT)
            F(4153, LVM_SUBITEMHITTEST)
            F(4154, LVM_SETCOLUMNORDERARRAY)
            F(4155, LVM_GETCOLUMNORDERARRAY)
            F(4156, LVM_SETHOTITEM)
            F(4157, LVM_GETHOTITEM)
            F(4158, LVM_SETHOTCURSOR)
            F(4159, LVM_GETHOTCURSOR)
            F(4160, LVM_APPROXIMATEVIEWRECT)
            F(4161, LVM_SETWORKAREAS)
            F(4162, LVM_GETSELECTIONMARK)
            F(4163, LVM_SETSELECTIONMARK)
            F(4164, LVM_SETBKIMAGEA)
            F(4165, LVM_GETBKIMAGEA)
            F(4166, LVM_GETWORKAREAS)
            F(4167, LVM_SETHOVERTIME)
            F(4168, LVM_GETHOVERTIME)
            F(4169, LVM_GETNUMBEROFWORKAREAS)
            F(4170, LVM_SETTOOLTIPS)
            F(4171, LVM_GETITEMW)
            F(4172, LVM_SETITEMW)
            F(4173, LVM_INSERTITEMW)
            F(4174, LVM_GETTOOLTIPS)
            F(4179, LVM_FINDITEMW)
            F(4183, LVM_GETSTRINGWIDTHW)
            F(4191, LVM_GETCOLUMNW)
            F(4192, LVM_SETCOLUMNW)
            F(4193, LVM_INSERTCOLUMNW)
            F(4211, LVM_GETITEMTEXTW)
            F(4212, LVM_SETITEMTEXTW)
            F(4213, LVM_GETISEARCHSTRINGW)
            F(4214, LVM_EDITLABELW)
            F(4235, LVM_GETBKIMAGEW)
            F(4236, LVM_SETSELECTEDCOLUMN)
            F(4237, LVM_SETTILEWIDTH)
            F(4238, LVM_SETVIEW)
            F(4239, LVM_GETVIEW)
            F(4241, LVM_INSERTGROUP)
            F(4243, LVM_SETGROUPINFO)
            F(4245, LVM_GETGROUPINFO)
            F(4246, LVM_REMOVEGROUP)
            F(4247, LVM_MOVEGROUP)
            F(4250, LVM_MOVEITEMTOGROUP)
            F(4251, LVM_SETGROUPMETRICS)
            F(4252, LVM_GETGROUPMETRICS)
            F(4253, LVM_ENABLEGROUPVIEW)
            F(4254, LVM_SORTGROUPS)
            F(4255, LVM_INSERTGROUPSORTED)
            F(4256, LVM_REMOVEALLGROUPS)
            F(4257, LVM_HASGROUP)
            F(4258, LVM_SETTILEVIEWINFO)
            F(4259, LVM_GETTILEVIEWINFO)
            F(4260, LVM_SETTILEINFO)
            F(4261, LVM_GETTILEINFO)
            F(4262, LVM_SETINSERTMARK)
            F(4263, LVM_GETINSERTMARK)
            F(4264, LVM_INSERTMARKHITTEST)
            F(4265, LVM_GETINSERTMARKRECT)
            F(4266, LVM_SETINSERTMARKCOLOR)
            F(4267, LVM_GETINSERTMARKCOLOR)
            F(4269, LVM_SETINFOTIP)
            F(4270, LVM_GETSELECTEDCOLUMN)
            F(4271, LVM_ISGROUPVIEWENABLED)
            F(4272, LVM_GETOUTLINECOLOR)
            F(4273, LVM_SETOUTLINECOLOR)
            F(4275, LVM_CANCELEDITLABEL)
            F(4276, LVM_MAPINDEXTOID)
            F(4277, LVM_MAPIDTOINDEX)
            F(4278, LVM_ISITEMVISIBLE)
            F(8192, OCM__BASE)
            F(8197, LVM_SETUNICODEFORMAT)
            F(8198, LVM_GETUNICODEFORMAT)
            F(8217, OCM_CTLCOLOR)
            F(8235, OCM_DRAWITEM)
            F(8236, OCM_MEASUREITEM)
            F(8237, OCM_DELETEITEM)
            F(8238, OCM_VKEYTOITEM)
            F(8239, OCM_CHARTOITEM)
            F(8249, OCM_COMPAREITEM)
            F(8270, OCM_NOTIFY)
            F(8465, OCM_COMMAND)
            F(8468, OCM_HSCROLL)
            F(8469, OCM_VSCROLL)
            F(8498, OCM_CTLCOLORMSGBOX)
            F(8499, OCM_CTLCOLOREDIT)
            F(8500, OCM_CTLCOLORLISTBOX)
            F(8501, OCM_CTLCOLORBTN)
            F(8502, OCM_CTLCOLORDLG)
            F(8503, OCM_CTLCOLORSCROLLBAR)
            F(8504, OCM_CTLCOLORSTATIC)
            F(8720, OCM_PARENTNOTIFY)
            F(32768, WM_APP)
            F(52429, WM_RASDIALEVENT)
    }
#undef F
    return 0;
}


namespace DragAPI {
	LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

	

	class WindowsWindow : public Window {
	public:
		HANDLE m_Handle;
		WNDCLASSEX m_WindowClass;

		std::wstring m_Tittle;

        DragAPI::Events::EventDispatcher* m_EventDispatcher;

        WindowsWindow(DragAPI::Events::EventDispatcher* dispatcher) :
            m_Handle(INVALID_HANDLE_VALUE),
            m_WindowClass(),
            m_Tittle(L""),
            m_EventDispatcher(dispatcher)
		{
			

		}

		~WindowsWindow() {
		}

		void Initialize(const wchar_t* tittle, Rect<int> rect) override {
			this->m_Tittle = std::wstring(tittle);


			m_WindowClass.cbSize = sizeof(m_WindowClass);
			m_WindowClass.style = CS_HREDRAW | CS_VREDRAW;
			m_WindowClass.lpfnWndProc = DragAPI::WndProc;
			m_WindowClass.cbClsExtra = 0;
			m_WindowClass.cbWndExtra = 0;
			m_WindowClass.hInstance = GetModuleHandle(NULL);
			m_WindowClass.hIcon = NULL;
			m_WindowClass.hCursor = NULL;
			m_WindowClass.hbrBackground = NULL;
			m_WindowClass.lpszMenuName = NULL;
			m_WindowClass.lpszClassName = TEXT("DragAPI::WindowClass");
			m_WindowClass.hIconSm = NULL;

			ATOM l_RegisterClassResult = RegisterClassEx(&this->m_WindowClass);
			DRAG_API_ASSERT(l_RegisterClassResult != 0, "RegisterClassEx failed. GetLastError = %d", GetLastError());


            //_CrtDbgReport(_CRT_WARN, NULL, NULL, NULL, "Creating a window and adding %p as a extra parameter.\n", this);
			this->m_Handle = CreateWindowEx(WS_EX_ACCEPTFILES, m_WindowClass.lpszClassName, tittle, WS_OVERLAPPEDWINDOW | WS_CAPTION, rect.xMin, rect.yMin, rect.Width(), rect.Height(), NULL, NULL, m_WindowClass.hInstance, this);
            
            DRAG_API_ASSERT(this->m_Handle != NULL, "CreateWindowEx failed. GetLastError = %d", GetLastError());

			
		}

		virtual void Destroy() override {
			DestroyWindow((HWND)this->m_Handle);
		}

		virtual void Show() override {
			ShowWindow((HWND)this->m_Handle, SW_SHOWNORMAL);
		}
		virtual void Hide() override {
			ShowWindow((HWND)this->m_Handle, SW_HIDE);
		}

		virtual void Process() override {
			MSG msg;
			ZeroMemory(&msg, sizeof(msg));
			while (::PeekMessage(&msg, (HWND)this->m_Handle, 0, 0, PM_REMOVE)) {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
            m_EventDispatcher->Dispatch();
		}

        virtual void SetEventDispatcher(DragAPI::Events::EventDispatcher* e) override {
            this->m_EventDispatcher = e;
        }

		std::wstring ToWString() {
			return std::wstring(this->m_Tittle);
		}
	};


	Window* Window::Create(const wchar_t* tittle, Rect<int> rect, DragAPI::Events::EventDispatcher* dispatcher) {
		Window* retVal = new WindowsWindow(dispatcher);
		retVal->Initialize(tittle, rect);
		return retVal;
	}


	LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		WindowsWindow* l_Window = nullptr;
		if (msg == WM_NCCREATE) {
			CREATESTRUCT* pCreate = reinterpret_cast<CREATESTRUCT*>(lParam);
			l_Window = reinterpret_cast<WindowsWindow*>(pCreate->lpCreateParams);

			SetLastError(0);//The function SetWindowLongPtr does not clear the last error. Therefore this is needed.
			LONG_PTR l_Result = SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)l_Window);
			DRAG_API_ASSERT(GetLastError() == 0, "SetWindowLongPtr failed. GetLastError returned %d", GetLastError());
		}
		else {
			SetLastError(0);//The function GetWindowLongPtr does not clear the last error. Therefore this is needed.
			LONG_PTR ptr = GetWindowLongPtr(hwnd, GWLP_USERDATA);
            if (ptr == 0) {//This is a hacky way of doing this. 
                return DefWindowProc(hwnd, msg, wParam, lParam);
            }
			DRAG_API_ASSERT(GetLastError() == 0, "GetWindowLongPtr failed. GetLastError returned %d", GetLastError());
			l_Window = reinterpret_cast<WindowsWindow*>(ptr);
            
		}


        DragAPI::Events::Event* e = nullptr;
		switch (msg) {
		case WM_NCCREATE:
			break;
        case WM_CREATE:
            e = new DragAPI::Events::WindowCreateEvent(l_Window);
            break;
        case WM_CLOSE:
            e = new DragAPI::Events::WindowCloseEvent(l_Window);
            break;
        case WM_DESTROY:

            break;
        case WM_KEYDOWN:
            e = new DragAPI::Events::KeyboardPressedEvent();
            break;
        case WM_KEYUP:
            e = new DragAPI::Events::KeyboardReleasedEvent();
            break;
		default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
		}
        if (l_Window != nullptr) {//This should be an assert. l_Window should never be nullptr.
            if (e != nullptr) {//The variable "e" should be null only when an event is not handeled here.
                l_Window->m_EventDispatcher->PushEvent(e);
            }
        }
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
}
#endif