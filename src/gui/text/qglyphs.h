/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtGui module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the Technology Preview License Agreement accompanying
** this package.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QGLYPHS_H
#define QGLYPHS_H

#include <QtCore/qsharedpointer.h>
#include <QtCore/qvector.h>
#include <QtCore/qpoint.h>
#include <QtGui/qfont.h>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(Gui)

class QGlyphsPrivate;
class Q_GUI_EXPORT QGlyphs
{
public:
    QGlyphs();
    QGlyphs(const QGlyphs &other);
    ~QGlyphs();

    QFont font() const;
    void setFont(const QFont &font);

    QVector<quint32> glyphIndexes() const;
    void setGlyphIndexes(const QVector<quint32> &glyphIndexes);

    QVector<QPointF> positions() const;
    void setPositions(const QVector<QPointF> &positions);

    void clear();

    QGlyphs &operator=(const QGlyphs &other);
    bool operator==(const QGlyphs &other) const;
    bool operator!=(const QGlyphs &other) const;

private:
    friend class QGlyphsPrivate;
    friend class QTextLine;

    QGlyphs operator+(const QGlyphs &other) const;
    QGlyphs &operator+=(const QGlyphs &other);

    void detach();
    QExplicitlySharedDataPointer<QGlyphsPrivate> d;

};

QT_END_NAMESPACE

QT_END_HEADER


#endif // QGLYPHS_H