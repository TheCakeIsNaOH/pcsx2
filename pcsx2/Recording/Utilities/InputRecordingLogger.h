/*  PCSX2 - PS2 Emulator for PCs
 *  Copyright (C) 2002-2020  PCSX2 Dev Team
 *
 *  PCSX2 is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU Lesser General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  PCSX2 is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with PCSX2.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "App.h"
#include "ConsoleLogger.h"
#include "DebugTools/Debug.h"
#include "Utilities/Console.h"

#include <fmt/core.h>

#include <memory>
#include <string>
#include <vector>

namespace inputRec
{
	static void log(const std::string& log)
	{
		if (log.empty())
			return;

		recordingConLog(fmt::format("[REC]: %s\n", log));

		// NOTE - Color is not currently used for OSD logs
		if (GSosdLog)
			GSosdLog(log.c_str(), wxGetApp().GetProgramLog()->GetRGBA(ConsoleColors::Color_StrongMagenta));
	}

	static void consoleLog(const std::string& log)
	{
		if (log.empty())
			return;

		recordingConLog(fmt::format("[REC]: %s\n", log));
	}

	static void consoleMultiLog(std::vector<std::string> logs)
	{
		std::string log;
		for (std::string l : logs)
			log.append(fmt::format("[REC]: %s\n", l));

		recordingConLog(log);
	}


	static void consoleMultiLog(std::vector<wxString> logs)
	{
		std::vector<std::string> stdLogs;
		for (wxString l : logs)
			stdLogs.push_back(std::string(l));

		consoleMultiLog(stdLogs);
	}
} // namespace inputRec