<?php
/*
  This code is part of FusionDirectory (http://www.fusiondirectory.org/)
  Copyright (C) 2014-2019  FusionDirectory
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
*/

class bolkData extends simplePlugin
{
  var $displayHeader  = FALSE;
  var $objectclasses = ["fdBolkData"];

  static function plInfo (): array
  {
    return [
      'plShortName'     => _('BolkData'),
      'plDescription'   => _('Bolk member information'),
      'plFilter'        => '(objectClass=fdBolkData'),
      'plSelfModify'    => TRUE,
      'plObjectClass'   => ['fdBolkData'],
      'plObjectType'    => ['user'],
	  'plIcon'          => 'geticon.php?context=applications&icon=user-info&size=48',
      'plSmallIcon'     => 'geticon.php?context=applications&icon=user-info&size=16',
      'plPriority'      => 2,

      'plProvidedAcls'  => parent::generatePlProvidedAcls(static::getAttributesInfo())
    ];
  }

  static function getAttributesInfo (): array
  {
    return [];
  }
}
