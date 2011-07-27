/*
 iosdisplay.m
 Copyright (C) 2011 Belledonne Communications, Grenoble, France
 
 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import <OpenGLES/EAGL.h>
#import <OpenGLES/EAGLDrawable.h>
#import <OpenGLES/ES2/gl.h>
#include "mediastreamer2/msfilter.h"

@interface IOSDisplay : UIView {
    UIView* imageView;
@private
    EAGLContext* context;
    
    GLuint defaultFrameBuffer, colorRenderBuffer;
    GLuint sampleFrameBuffer, sampleColorRenderBuffer;
    GLuint program, textures[3];
    GLint backingWidth;
    GLint backingHeight;
    
    id displayLink;
    BOOL animating;
    
    mblk_t *latestYuv;
}

- (void) drawView:(id)sender;
- (void) startRendering:(id)ignore;
- (void) stopRendering;


//@property (nonatomic, retain) UIImageView* imageView;
@end
