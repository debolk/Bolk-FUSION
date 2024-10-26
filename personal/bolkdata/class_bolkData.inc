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
  // We set displayHeader to FALSE, because we don't want a header allowing to activate/deactivate this plugin,
  // we want it activated on all objects
  var $displayHeader = FALSE;

  // We need this function that returns some information about the plugin
  static function plInfo (): array
  {
    return [
      'plShortName'       => _('Demo Plugin'),
      'plTitle'           => _('Demo Plugin informations'),
      'plDescription'     => _('Edit some useless personal information'),
      'plSelfModify'      => TRUE, // Does this plugin have an owner that might be able to edit its entry
      'plObjectType'      => ['user'],
      'plObjectClass'     => ['demoPlugin'],

      // simplePlugin can generate the ACL list for us
      'plProvidedAcls'    => parent::generatePlProvidedAcls(self::getAttributesInfo())
    ];
  }

  // The main function : information about attributes
  static function getAttributesInfo (): array
  {
    return [
    ];
  }
}
