#-------------------------------------------------
#
# Project created by QtCreator 2022-01-19T17:10:59
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtExam
TEMPLATE = app


SOURCES += main.cpp\
        connexion_fen.cpp \
    inscription_fen.cpp \
    message_fen.cpp \
    bd_connexion.cpp \
    Invitations.cpp \
    Messages.cpp \
    Users.cpp

HEADERS  += connexion_fen.h \
    inscription_fen.h \
    message_fen.h \
    bd_connexion.h \
    Invitations.h \
    Messages.h \
    Users.h

FORMS    += connexion_fen.ui \
    inscription_fen.ui \
    message_fen.ui

DISTFILES += \
    QtExam.pro.user \
    message.db
