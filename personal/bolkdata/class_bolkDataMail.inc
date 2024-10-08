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

class bolkDataMail extends simplePlugin
{
  var $displayHeader  = TRUE;
  var $objectclasses = ["fdBolkDataMail"];

  static function plInfo (): array
  {
    return [
      'plShortName'     => _('BolkData Mail'),
      'plDescription'   => _('Bolk mail information'),
      'plSelfModify'    => TRUE,
      'plObjectType'    => ['group'],
      'plIcon'          => 'geticon.php?context=applications&icon=user-info&size=48',
      'plSmallIcon'     => 'geticon.php?context=applications&icon=user-info&size=16',
      'plPriority'      => 1,

      'plProvidedAcls'  => parent::generatePlProvidedAcls(static::getAttributesInfo())
    ];
  }

  static function getAttributesInfo (): array
  {
    return [
      'main' => [
        'name'  => _('Bolk Mail info'),
        'attrs' => [
          new StringAttribute(
            _('Parent Mail Address'), _('Parent e-mail address which this e-mail inherits ACL\'s from'),
            'fdParentMail'
          ),
		]
	  ]
    ];
  }
}
