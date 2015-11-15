import QtQuick 2.0
import Sailfish.Silica 1.0

import harbour.subsoniq 1.0

Dialog
{
	SettingsPageViewModel
	{
		id: model
	}

	SilicaFlickable
	{
		anchors
		{
			fill: parent
		}

		DialogHeader
		{
			id: header
		}

		Column
		{
			anchors
			{
				top: header.bottom
			}

			width: parent.width
			spacing: Theme.paddingLarge

			TextField
			{
				id: serverUrl
				placeholderText: "Server URL"
				label: placeholderText
				width: parent.width
				text: model.serverUrl

				Binding
				{
					target: model
					property: "serverUrl"
					value: serverUrl.text
				}
			}

			TextField
			{
				id: username
				placeholderText: "Username"
				label: placeholderText
				width: parent.width
				text: model.username

				Binding
				{
					target: model
					property: "username"
					value: username.text
				}
			}

			TextField
			{
				id: password
				placeholderText: "Password"
				label: placeholderText
				width: parent.width
				echoMode: TextInput.Password
				text: model.password

				Binding
				{
					target: model
					property: "password"
					value: password.text
				}
			}
		}
	}
}