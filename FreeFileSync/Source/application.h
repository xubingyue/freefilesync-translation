// *****************************************************************************
// * This file is part of the FreeFileSync project. It is distributed under    *
// * GNU General Public License: http://www.gnu.org/licenses/gpl-3.0           *
// * Copyright (C) Zenju (zenju AT freefilesync DOT org) - All Rights Reserved *
// *****************************************************************************

#ifndef APPLICATION_H_081568741942010985702395
#define APPLICATION_H_081568741942010985702395

#include <vector>
#include <zen/zstring.h>
#ifdef ZEN_WIN
    #include <zen/win.h> //include before <wx/msw/wrapwin.h>
#endif
#include <wx/app.h>
#include "lib/return_codes.h"


class Application : public wxApp
{
private:
    bool OnInit() override;
    int  OnRun() override;
    int  OnExit() override;
    bool OnExceptionInMainLoop() override { throw; } //just re-throw and avoid display of additional messagebox: it will be caught in OnRun()

    void onEnterEventLoop(wxEvent& event);
    void onQueryEndSession(wxEvent& event);
    void launch(const std::vector<Zstring>& commandArgs);

    zen::FfsReturnCode returnCode = zen::FFS_RC_SUCCESS;
};

#endif //APPLICATION_H_081568741942010985702395
