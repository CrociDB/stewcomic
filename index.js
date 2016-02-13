'use strict';

var app = require('app');
var BrowserWindow = require('browser-window');

app.on('window-all-closed', function() {
    if (process.platform != 'darwin') {
        app.quit();
    }
});

app.on('ready', function() {
    initWindow();
});

var initWindow = function() {
    var mainWindow = new BrowserWindow({
        width: 1280,
        height: 720
    });

    mainWindow.on('closed', function() {
        mainWindow = null;
    });

    mainWindow.loadURL('file://' + __dirname + '/index.html');
    //mainWindow.openDevTools();
};
