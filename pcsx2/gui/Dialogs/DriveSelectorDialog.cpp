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

#include "PrecompiledHeader.h"
#include "Dialogs/ModalPopups.h"
#include "../CDVD/CDVDdiscReader.h"

Dialogs::DriveSelectorDialog::DriveSelectorDialog(wxWindow* parent, wxString curDrive)
	: wxDialog(parent, wxID_ANY, "")
{
	wxBoxSizer* topSizer = new wxBoxSizer(wxVERTICAL);
	wxStaticBoxSizer* staticSizer = new wxStaticBoxSizer(wxVERTICAL, this, "Source drive...");
	wxBoxSizer* btnSizer = new wxBoxSizer(wxHORIZONTAL);

	auto drives = GetOpticalDriveList();
	wxArrayString driveList;

	for (auto i : drives)
	{
		driveList.Add(i);
	}

	choiceDrive = new wxChoice(this, wxID_ANY, wxDefaultPosition, { 240, 40 }, driveList);

	int driveIndex = choiceDrive->FindString(curDrive);
	if (driveIndex != wxNOT_FOUND)
	{
		choiceDrive->SetSelection(driveIndex);
	}

	wxButton* btnOk = new wxButton(this, wxID_OK);
	wxButton* btnCancel = new wxButton(this, wxID_CANCEL);

	btnSizer->Add(btnOk, wxSizerFlags(1).Expand());
	btnSizer->Add(btnCancel, wxSizerFlags(1).Expand().Border(wxLEFT, 5));

	staticSizer->Add(choiceDrive, wxSizerFlags(1).Expand().Border(wxTOP, 10).Border(wxLEFT, 7));
	topSizer->Add(staticSizer, wxSizerFlags(2).Expand().Border(wxALL, 10));
	topSizer->Add(btnSizer, wxSizerFlags(0).Border(wxRIGHT | wxLEFT | wxBOTTOM, 5).Right());
	SetSizerAndFit(topSizer);
}

wxString Dialogs::DriveSelectorDialog::GetSelectedDrive()
{
	return choiceDrive->GetStringSelection();
}